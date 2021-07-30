#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums{1,2,3,4};
    for(auto n:nums)
    {
        cout << n << " ";
    }
    cout << endl;
    for(auto &n:nums)
    {
        n = n + 1;
    }

    for_each(nums.begin(),nums.end(),[](int x){cout<<x<<" ";});
    return 0;
}