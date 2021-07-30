#include <iostream>
using namespace std;

int func()
{
    return 0;
}

int main()
{
    //decltype选择并返回操作数的数据类型
    {
        const int ci = 0,&cj = ci;
        decltype(ci) x = 0;
        //y是一个引用必须初始化
        decltype(cj) y = x;
        decltype(func()) i = 0;
        cout << typeid(x).name() << endl;
        cout << typeid(y).name() << endl;
        cout << typeid(i).name() << endl;
    }

    {
        int i = 42,*p = &i,&r = i;
        //加法的结果是int,b可以是一个未初始化的值
        decltype(r+0) b;
        //c是int& 必须初始化
        decltype(*p) c = b;
        cout << typeid(b).name() << endl;
        cout << typeid(c).name() << endl;
    }

    {
        int i = 1;
        //decltype((v))  双重括号的结果永远是引用
        decltype(i) a = 1;
        decltype((i)) b = a;
        cout << typeid(a).name() << endl;
        cout << typeid(b).name() << endl;
    }
    return 0;
}