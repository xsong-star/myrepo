#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a1 = 0;
    int a2 = {0};
    int a3{0};
    int a4(0);

    //如果我们使用列表初始化且初始化存在丢失信息
    /*
    long double id = 3.1415926;
    int a{id},b = {id};//转换未执行，存在丢失信息的危险
    int c(id),b = id;//转换执行，丢失了部分信息
    */
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
    cout << a4 << endl;
    
    return 0;
}