#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums,int l,int mid, int r)
{
    vector<int> tmp = nums;
    int i = l, j = mid+1;
    int index = l;
    while(i <= mid || j <= r)
    {
        if(i>mid)
        {
            nums[index++] = tmp[j];
            j++;
        }
        else if(j>r)
        { 
            nums[index++] = tmp[i];
            i++;
        }
        else if(tmp[i]<tmp[j])
        {
            nums[index++] = tmp[i];
            i++;
        }
        else
        {
            nums[index++] = tmp[j];
            j++;
        }
    }
}

void merge_sort(vector<int>& nums,int l,int r)
{
    if(l >= r)
        return;
    int mid = l + (r-l)/2;
    merge_sort(nums,l,mid);
    merge_sort(nums,mid+1,r);
    if(nums[mid]>nums[mid+1])
        merge(nums,l,mid,r);
}

void mergeSort(vector<int>&nums)
{
    int n = nums.size();
    merge_sort(nums,0,n-1);
}

int main()
{
    vector<int> nums{5,1,2,4,6,2,9};
    mergeSort(nums);
    for_each(nums.begin(),nums.end(),[](int x){ cout << x << " ";});
    cout << endl;
    return 0;
}