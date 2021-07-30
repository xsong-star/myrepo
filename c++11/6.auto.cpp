#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i = 1,j = 2;
    auto k = i+j;
    double m = 3.1231;
    //n,l值必须相同
    //auto n = i+j,l = m;
    
    cout << typeid(k).name() << endl;
    return 0;
}