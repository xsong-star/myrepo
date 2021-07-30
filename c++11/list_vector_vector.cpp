#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //列表初始化向量的向量
    vector<string> vs1{"a","ab","abc"};
    //vector<string> vs2("a","ab","abc");---错误
    for_each(vs1.begin(),vs1.end(),[](string s){cout<<s<<endl;});
    return 0;
}