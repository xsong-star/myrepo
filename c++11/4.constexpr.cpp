#include <iostream>
#include <vector>
using namespace std;

constexpr int size()
{
    return 3;
}


int main()
{
    
    constexpr int pm1 = 2;
    constexpr int pm2 = pm1+1;
    //只有size()返回值常量表达式时候，变量的时候就可以计算其值。
    constexpr int pm3 = size();

    cout << pm1 << endl;
    cout << pm2 << endl;
    cout << pm3 << endl;
    return 0;
}
