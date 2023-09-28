// Leetcode problem number 167: Two sum (2) Input array is sorted..... [SAME LIKE Key pair problem in gfg]
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
// find two numbers such that they add up to a specific target number.   Input: numbers = [2,7,11,15], target = 9
//                                                                       Output: [1,2]
#include<iostream>
#include<vector>
using namespace std;
 vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int l = 0;
        int h = nums.size()-1;
        int curentSum = 0;
        while(l<h){
            if(nums[l] + nums[h] == target){
                ans.push_back(l+1);
                ans.push_back(h+1);
                break;
            }
            else if(nums[l] + nums[h] > target){
                h--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
int main()
{
    int n , target;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    vector<int> nums;
    vector<int> ans;
    cout<<"Enter the elements : "<<endl;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    cout<<"Enter the target element: "<<endl;
    cin>>target;

    ans = twoSum(nums , target);
    
    cout<<"pairs(indexes) which is sum of equal to the target is(according to 1 based indexing) : "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}