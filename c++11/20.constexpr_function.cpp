#include <iostream>
using namespace std;

//constexpr函数只能用于常量表达式
constexpr int new_sz()
{
    return 42;
}

//内联函数和常量表达式函数通常定义在头文件中，多个定义必须完全一致
constexpr size_t scale(size_t cnt)
{
    return new_sz()*cnt;
}

int main()
{
    constexpr int foo = new_sz();
    int a1[scale(2)];
    volatile int i = 2;
    //scale(i)不是常量表达式
    int a2[scale(i)];
}