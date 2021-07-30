#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5};
    auto cit = v.cbegin();
    //cit的类型为const_iterator
    cout << typeid(cit).name() << endl;
    return 0;
}