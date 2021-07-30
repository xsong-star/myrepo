#include <iostream>
using namespace std;

int main()
{
    //标准库中的begin和end函数
    int a[] = {1,2,3,4,5};
    int *beg = begin(a);
    int *last = end(a);
    //指向a的首元素和末尾元素的下一个指针
    while(beg!=last)
    {
        cout << *beg << " ";
        beg++;
    }
    cout << endl;
    return 0;
}
