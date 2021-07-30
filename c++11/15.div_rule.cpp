#include <iostream>
using namespace std;

int main()
{
    //早期版本商为负值，允许向上和向下取整
    //c++11只允许向0取整，直接去除小数位
    int a = -7;
    int b = 2;
    cout << a/2 << endl;
    return 0;
}