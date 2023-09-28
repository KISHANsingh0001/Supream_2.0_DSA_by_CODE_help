//                     Leet code problem number 724. Find Pivot Index
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is 
// equal to the sum of all the numbers strictly to the index's right.       Input: nums = [1,7,3,6,5,6]
//                                                                          Output: 3
#include<iostream>
#include<vector>
using namespace std;
    int preFixSumApproch(vector<int>& nums){
        vector<int>lsum(nums.size() , 0); // create vector lsum with equal size of the nums.
        vector<int>rsum(nums.size() , 0); // create vector rsum with equal size of the nums.

    //  This loop calculates the left sum of the array elements 
        for(int i = 1; i<nums.size() ; i++){
            lsum[i] = lsum[i-1] + nums[i-1];
        }

    //  this loop calculates the right sum of the array elements
         for(int i = nums.size()-2; i >= 0 ; i--){
            rsum[i] = rsum[i+1] + nums[i+1];
        }
        for(int i = 0 ; i<lsum.size() ; i++){
            if(lsum[i] == rsum[i]){
                return i;
            }
        }
        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        return preFixSumApproch(nums);
    }
int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    vector<int> nums;
    cout<<"Enter the elements : "<<endl;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    int ans = pivotIndex(nums);
    
     cout<<"Pivot index is: "<<ans << endl;

    return 0;
}