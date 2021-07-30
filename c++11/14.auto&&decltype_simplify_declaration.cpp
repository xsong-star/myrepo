#include <iostream>
using namespace std;

int main()
{
    int ia[3][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
    int (*p)[4] = ia;//p指向含有四个整数的数组
    p = &ia[2];//p指向ia的尾元素

    for(auto p = begin(ia);p != end(ia); ++p)
    {
        for(auto q = begin(*p);q != end(*p);++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}