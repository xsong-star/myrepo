#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//尾置返回类型
auto func()->vector<int>
{
    //列表初始化返回值
    return {1,2,3,4};
}

int main()
{
    vector<int> v(func());
    for_each(v.begin(),v.end(),[](int x){cout<<x<<" ";});
    cout << endl;
    return 0;
}