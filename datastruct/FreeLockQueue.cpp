#include <atomic>
#include <iostream>
#include <assert.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <ctime>
#include <exception>
using namespace std;

template <typename T>
class FreeLockQueue
{
private:
	struct queueNode
	{
		atomic<queueNode*> next;
		atomic<T> val;
		queueNode(T v):val(v),next(nullptr){}
		queueNode(){}
	};

	atomic<queueNode*> head_;
	atomic<queueNode*> tail_;
	atomic<int> count_ = {0};
	
public:
	FreeLockQueue()
	{
		queueNode* dummyNode = new queueNode(0);	
		head_.store(dummyNode);
		tail_.store(dummyNode);
	}
	FreeLockQueue(const FreeLockQueue&x) = delete;
	~FreeLockQueue()
	{
		while(head_ != nullptr)
    	{
        	queueNode* p = head_.load();
        	head_.store(p->next);
        	delete p;
    	}
	}

	void Push(const T&x);
	void tryPop(T &val);
};

template <typename T>
void FreeLockQueue<T>::Push(const T&x)
{
	queueNode* node = new queueNode(x);
	while(true)
	{
		queueNode* last = tail_.load();
		queueNode* next = last->next.load();
		//当t == nullptr 说明tail锁被抢占
		if(last == tail_.load())
		{
			if(next == nullptr)
			{
				if(last->next.compare_exchange_weak(next,node))
				{
					tail_.compare_exchange_weak(last,node);
					return;
				}
			}
			else
			{
				tail_.compare_exchange_weak(last,next);
			}
		}
	}
}

template <typename T>	
void FreeLockQueue<T>::tryPop(T &val)
{
	while(true)
	{
		queueNode* first = head_.load();
		queueNode* last = tail_.load();
		queueNode* next = first->next.load();
		if(first == head_.load())
		{
			if(first == last)
			{
				if(next == nullptr)
				{
					throw "head_ = tail_";
				}
				tail_.compare_exchange_weak(last,next);
			}
			else
			{
				T value = next->val;
				if(head_.compare_exchange_weak(first,next))
				{
					val = value;
					delete first;
					return;
				}
			}
		}
	}
}


FreeLockQueue<int> queue_;
const int pn = 1,cn = 1;
atomic<int> cnt(0);
mutex mutex_;
condition_variable cond_;
bool running = false;

void produce(){
	{
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock,[](){return running;});
	}
	for(int i = 0;i<1;i++)
	{
		for(int j = 1;j<=1;j++)
		{
			queue_.Push(j);
		}
	}
	cnt++;
}

void consume()
{	
	{
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock,[](){return running;});
	}
	int val;
	
	while(true)
	{
		queue_.tryPop(val);
		if(cnt == pn)
			break;
	}
}

int main()
{
	vector<thread> pthread,cthread;
	for(int i = 0;i<pn;i++)
	{
		pthread.push_back(thread(&produce));
	}
	for(int j = 0;j<cn;j++)
	{
		cthread.push_back(thread(&consume));
	}

	auto start = time(NULL);
	{
		std::lock_guard<std::mutex> guard(mutex_);
		running = true;
		cond_.notify_all();
	}
	for(int i = 0;i<pn;i++)	pthread[i].join();
	for(int j = 0;j<cn;j++)	pthread[j].join();
	auto end = time(NULL);

	cout << " time = " << end-start << endl;
	return 0;
}