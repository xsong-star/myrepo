#include <iostream>
using namespace std;

int main()
{
    //传统类型别名
    typedef int mint1;
    mint1 i = 4;
    //c++11类型别名
    using mint2 = double;
    mint2 j = 3;

    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    return 0;
}