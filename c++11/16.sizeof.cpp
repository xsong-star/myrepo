#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    char a = 'a';
    constexpr char b = 'b';
    //对char或者char常量表达式，结果为1
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    char &c = a;
    //对引用类型sizeof得到的是被引用类型所占空间的大小
    cout << sizeof(c) << endl;
    int *p;
    //对指针执行sizeof返回指针本身所占空间大小
    //对指针解引用执行sizeof返回对象所占大小
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << " " << sizeof(int)<< endl;
    //对数组执行sizeof返回整个数组所占空间
    int q[4] = {1,2,3,4};
    cout << sizeof(q) <<endl;
    //对string或vector对象sizeof只会返回固定部分的大小，不会返回对象中元素占的空间
    vector<int> v{1,2,3,4};
    string s("abcd");
    cout << sizeof(v) << " " << "capacity = " << v.capacity() << endl;
    cout << sizeof(s) << " " << "capacity = " << s.capacity() << endl;

    return 0;
}