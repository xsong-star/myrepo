#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void buildHeap(vector<int>&nums,int i,int len)
{
    int lchild = i*2 + 1;
    
    if(lchild < len)
    {
        int flag = lchild;
        int rchild = lchild+1;
        if(rchild < len)
        {
            if(nums[rchild]>nums[lchild])
            {
                flag = rchild;
            }
        }
        if(nums[i] < nums[flag])
        {
            swap(nums[i],nums[flag]);
            buildHeap(nums,flag,len);
        }
            
    }
}

void heapsort(vector<int>& nums)
{
    int n = nums.size();
    for(int i = n/2;i>=0;i--)
    {
        buildHeap(nums,i,n);
    }

    for(int j = n-1;j> 0;--j)
    {
        swap(nums[0],nums[j]);
        buildHeap(nums,0,j);
    }
}

int main()
{
    vector<int> nums{5,1,2,4,6,2,9};
    heapsort(nums);
    for_each(nums.begin(),nums.end(),[](int x){ cout << x << " ";});
    cout << endl;
    return 0;
}