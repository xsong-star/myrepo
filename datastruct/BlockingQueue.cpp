#include <mutex>
#include <condition_variable>
#include <deque>
#include <thread>
#include <assert.h>
#include <iostream>
#include <unistd.h>
using namespace std;
template <typename T>
class BlockingQueue {
public:
    using MutexLockGuard = std::lock_guard<std::mutex>;

    BlockingQueue()
        : _mutex(),
          _notEmpty(),
          _queue()
    {
    }

    BlockingQueue(const BlockingQueue &) = delete;
    BlockingQueue& operator=(const BlockingQueue &) = delete;

    void put(const T &x)
    {
        {
            MutexLockGuard lock(_mutex);
            _queue.push_back(x);
        }
        _notEmpty.notify_one();
    }

    void put(T &&x)
    {
        {
            MutexLockGuard lock(_mutex);
            _queue.push_back(std::move(x));
        }
        _notEmpty.notify_one();
    }

    T take()
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _notEmpty.wait(lock, [this]{  return !this->_queue.empty(); });  
        assert(!_queue.empty());

        T front(std::move(_queue.front()));
        _queue.pop_front();

        return  front;
    }

    size_t size() const 
    {
        MutexLockGuard lock(_mutex);
        return _queue.size();
    }

private:
    mutable std::mutex _mutex;
    std::condition_variable _notEmpty;
    std::deque<T> _queue;
};

void* func1(void*arg)
{
    BlockingQueue<int>* bq = static_cast<BlockingQueue<int>*>(arg);
    bq->put(1);
    bq->put(2);
    bq->put(3);
    bq->take();
    bq->size();
    cout << " thread1_ = "<< bq->size() << endl;
}

void* func2(void*arg)
{
    BlockingQueue<int>* bq = static_cast<BlockingQueue<int>*>(arg);
    bq->put(1);
    bq->put(2);
    sleep(1);
    bq->put(3);
    bq->take();
    bq->size();
 
    cout << " thread2_ = "<< bq->size() << endl;
}


void* func3(void*arg)
{
    BlockingQueue<int>* bq = static_cast<BlockingQueue<int>*>(arg);
    bq->put(1);
    bq->put(2);
    sleep(2);
    bq->put(3);
    bq->take();
    
    cout << " thread3_ = "<< bq->size() << endl;
}

int main()
{
    BlockingQueue<int>* bq = new BlockingQueue<int>();
    /*
        pthread_t thread1_;
        pthread_t thread2_;
        pthread_t thread3_;
        
        pthread_create(&thread1_,NULL,func1,bq);
        pthread_create(&thread2_,NULL,func2,bq);
        pthread_create(&thread3_,NULL,func3,bq);

        pthread_join(thread1_,NULL);
        pthread_join(thread2_,NULL);
        pthread_join(thread3_,NULL);
    */
    std::thread t1(func1,bq);
    std::thread t2(func2,bq);
    std::thread t3(func3,bq);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}