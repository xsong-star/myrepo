#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

/*
给定一个集合S(没有重复元素), 输出它所有的子集 输入 1 2 3 输出 1, 2, 12, 3, 13, 23, 123
*/

vector<vector<int>> sub(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    vector<int> cur;
    function<void(int)> dfs = [&](int idx)->void
    {
        if(idx == n+1)
            return;
        if(cur.size() != 0)
            res.push_back(cur);
        for(int i = idx;i<n;i++)
        {
            cur.push_back(nums[i]);
            dfs(i+1);
            cur.pop_back();
        }
    };
    dfs(0);
    return res;
}   

int main()
{
    vector<int> nums{1,2,3,4,5};
    vector<vector<int>> res = sub(nums);
    for_each(res.begin(),res.end(),[](vector<int> t){
        for_each(t.begin(),t.end(),[](int x){cout << x <<" ";});cout<<endl;});
}