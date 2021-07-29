#include <iostream>
#include <mutex>
using namespace std;
#define barrier() __asm__ volatile ("lwsync")

//懒汉模式---线程不安全
namespace s1{
    class singleton
    {
    private:
        singleton(){}
        static singleton *p;
    public:
        static singleton* getInstance();
    };

    singleton *singleton::p = nullptr;

    singleton* singleton::getInstance()
    {
        if(p == nullptr)
            p = new singleton();
        return p;
    }
}

//饿汉模式
namespace s2{
    class singleton
    {
    private:
        singleton(){}
        static singleton *p;
    public:
        static singleton* getInstance();
    };

    singleton *singleton::p = new singleton();

    singleton* singleton::getInstance()
    {
        return p;
    }
}

//懒汉模式---线程安全(性能低下-每次调用getInstance加锁)
namespace s3{
    class singleton
    {
    private:
        singleton(){}
        static singleton *p;
        static std::mutex mutex_;
    public:
        static singleton* getInstance();
    };

    singleton *singleton::p = nullptr;

    singleton* singleton::getInstance()
    {
        std::lock_guard<std::mutex> guard(mutex_);
        if(p == nullptr)
            p = new singleton();
        return p;
    }
}

//懒汉模式---线程安全(双重判断---内存乱序访问(编译器问题))
/*
    p = new singleton()
    1.分配存储singleton对象的内存。
    2.在内存中构造一个singlton对象。
    3.让p指向分配的内存
    2.3顺序不确定
    可能获取了一个没有构造出对象的内存空间
*/
namespace s3{
    class singleton
    {
    private:
        singleton(){}
        static singleton *p;
        static std::mutex mutex_;
    public:
        static singleton* getInstance();
    };

    singleton *singleton::p = nullptr;

    singleton* singleton::getInstance()
    {
        //当对象存在时,则不需要加锁
        if(p == nullptr)
        {
            std::lock_guard<std::mutex> guard(mutex_);
            barrier();
            if(p == nullptr)
                p = new singleton();
        }
        return p;
    }
}