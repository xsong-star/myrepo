#include <iostream>
#include <atomic>
#include <exception>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
using namespace std;

class exc: public std::exception
{
    const char* what() const throw();
};
const char* exc::what() const throw()
{
    return "\n\nDequeing from an empty queue!\n\n";
}
template<class T>
class lockFreeQueue
{
    struct Node
    {
        T value;
        std::atomic<Node*> next;
        Node(T value): value(value), next(nullptr) { }
        Node(): next(nullptr) { }
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;
    exc emptyQ;

public:

    lockFreeQueue();
    ~lockFreeQueue();

    void enq(const T& value);
    void deq(T& res);

    void print();
};
template<class T>
lockFreeQueue<T>::lockFreeQueue()
{
    head.store(new Node( T() ));
    tail = head.load();
}

template<class T>
lockFreeQueue<T>::~lockFreeQueue()
{
    while(head != nullptr)
    {
        Node* p = head.load();
        head.store(p->next);
        delete p;
    }
}

template<class T>
void lockFreeQueue<T>::enq(const T& value)
{
    Node* node = new Node(value);
    while(true)
    {
        Node* last = tail.load();
        Node* next = last->next.load();
        if(last == tail.load())
        {
            if(next == nullptr)
            {
                if(atomic_compare_exchange_weak(&(last->next), &next, node))
                {
                    atomic_compare_exchange_weak(&tail, &last, node);
                    return;
                }
            }
            else
            {
                atomic_compare_exchange_weak(&tail, &last, next);
            }
        }
    }
}

template<class T>
void lockFreeQueue<T>::deq(T& res)
{
    while(true)
    {
        Node* first = head.load();
        Node* last = tail.load();
        Node* next = first->next.load();
        if(first == head.load())
        {
            if(first == last)
            {
                if(next == nullptr)
                {
                    throw emptyQ;
                }
                atomic_compare_exchange_weak(&tail,&last,next);
            }
            else
            {
                T value = next->value;
                if(atomic_compare_exchange_weak(&head,&first,next))
                {
                    res = value;
                    return;
                }
            }
        }
    }
}

template<class T>
void lockFreeQueue<T>::print()
{
    Node* p;
    p = head.load()->next.load();
    cout << "HEAD -> ";
    while(p != nullptr)
    {
        cout << p->value;
        if(p->next.load() != nullptr) cout << "  ";
        else cout << " <- ";

        p = p->next.load();
    }
    cout << "TAIL\n";
}


lockFreeQueue<int> queue_;
const int pn = 1,cn = 1;
atomic<int> cnt(0);
mutex mutex_;
condition_variable cond_;
bool running = false;

atomic<int> i(0);

void produce(){
	{
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock,[](){return running;});
	}
	queue_.enq(i++);

}

void consume()
{	
	queue_.enq(i);
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
