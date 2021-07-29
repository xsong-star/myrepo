#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void quicksort(vector<int> &nums,int l,int r)
{
    //int base = nums[r];
    if(l>=r)
        return;
    int i = l,j = r;
    int flag = 0;
    while(i<j)
    {
        if(flag == 0)
        {
            if(nums[i] < nums[j])
            {
                i++;
            }  
            else
            {
                swap(nums[i],nums[j]);
                j--;
                flag = 1;
            }
        }
        else if(flag == 1)
        {
            if(nums[j] > nums[i])
            {
                j--;
            }    
            else
            {
                swap(nums[i],nums[j]);
                i++;
                flag = 0;
            }
        }
    }
    quicksort(nums,l,i-1);
    quicksort(nums,i+1,r);
}
void quick_sort(vector<int> &nums)
{
    int n = nums.size();
    quicksort(nums,0,n-1);
}

int main()
{
    vector<int> nums{5,1,2,4,6,2,3};
    quick_sort(nums);
    for_each(nums.begin(),nums.end(),[](int x){ cout << x << " ";});
    cout << endl;
}