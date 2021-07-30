#include <iostream>
using namespace std;

class testclass
{
public:
    //如果是在类的内部声明，则说明是内联的，如果是在类外部类就不是内联的
    testclass() = default;
};
