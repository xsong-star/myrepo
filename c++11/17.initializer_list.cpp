#include <initializer_list>
#include <string>
#include <iostream>
using namespace std;

class ErrorCode
{
private:
    int e_num;
public:
    ErrorCode(int error_num):e_num(error_num){}
    int msg()
    {
        return e_num;
    }
};


void error_msg(ErrorCode e,initializer_list<string> emsg)
{
    cout << e.msg() << ": ";
    for(auto &m:emsg)
    {
        cout << m << " ";
    }
    cout << endl;
}

//initializer_list 是一种标准库类型，用于表示某种特定类型的值数组
int main()
{
    initializer_list<int> lst1{1,2,3,4,5};
    //拷贝或者赋值一个initializer_list对象不会拷贝列表中的元素:拷贝元素列表和副本共享元素
    initializer_list<int> lst2(lst1);
    initializer_list<int> lst3 = lst1;

    //initializer_list的元素永远是常量值，我们无法改变initializer_list的值

    error_msg(ErrorCode(42),{"functionxx","failed!"});
}