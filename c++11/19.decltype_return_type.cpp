#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int odd[] = {1,2,3,4,5};
int even[] = {0,2,4,6,8};

//返回一个指针，该指针指向五个整形元素
decltype(odd) *arrptr(int i)
{
    return (i%2)?&odd:&even;//返回一个指向数组的指针
}

int main()
{
    auto nums = arrptr(2);
    for(auto n:(*nums))
    {
        cout << n <<" ";
    }
    cout << endl; 
    return 0;
}