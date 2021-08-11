#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    /*
    input:
        6 1 1 1 1
        1 1 2 3 1 1
    output:
        5
    */
    int N;
    cin >> N;
    int T1,T2,T3,T4;
    cin >> T1 >> T2 >> T3 >> T4;
    vector<int> Hi;
    for(int i = 0;i < N;i++)
    {
        int hi;
        cin >> hi;
        Hi.push_back(hi);
    }
    /*
    cout << N << endl;
    cout << T1 << " " << T2 << " " << T3 << " " << T4 << endl;
    for_each(Hi.begin(),Hi.end(),[&](int x)
    {
        cout << x << " ";
    });
    cout << endl;
    */
   
    return 0;
}