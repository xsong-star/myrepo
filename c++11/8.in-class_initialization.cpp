#include <iostream>
using namespace std;

struct st
{
    //类内初始化
    int a{0},b{0},c,d;
    st(int i,int j):c{i},d{j}{
        cout <<" a = "<< a << endl;
        cout <<" b = "<< b << endl;
        cout <<" c = "<< c << endl;
        cout <<" d = "<< d << endl;
    }
};


int main()
{
    st s(1,2);
    return 0;
}