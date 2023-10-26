#include<iostream>
#include<vector>
using namespace std;
void sortArrayHelper(vector<int>& nums , int start , int end){
     if(start >= end)
     { // base case
            return ;
     }

        int i = start - 1;
        int j = start;
        int pivot = end;
      

        while(j<pivot){
            if(nums[j] < nums[pivot]){
                ++i;
                swap(nums[j] , nums[i]);
            }
            j++;
        }
        ++i;
        swap(nums[i] , nums[pivot]);

        sortArrayHelper(nums , start , i-1);
        sortArrayHelper(nums , i+1 , end);
    }
int main()
{
    vector<int> nums = {7,2,1,8,6,3,5,4};
    sortArrayHelper(nums , 0 , nums.size()-1);
    for(auto i: nums){
        cout<<i<<" ";
    }
    return 0;
}