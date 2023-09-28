// Method number 1 using binary Search..
// Algorithm - 1) firstly we sort the array using sort function 
//             2) if nums[i] {1} and nums[i] + k {1+2=3} if 3 is present in nums array then we make pair of nums[i] and 
//                nums[i] + k and insert it into ans set.
//             3) binary search's code searches the nums[i] + k . 
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int bs(vector<int>& nums , int s , int x){
        int e = nums.size();
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == x){
                return mid;
            }
            else if(nums[mid] < x){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k)
   {
        // # Binary search approch 
        sort(nums.begin() , nums.end());
        set<pair<int ,int>>ans;
        for(int i = 0 ; i<nums.size(); i++){
            if(bs(nums , i+1 , nums[i] + k) != -1){
                ans.insert({nums[i] , nums[i]+k});
            }
        }
        return ans.size();

     }
int main()
{
    vector<int>nums = {1,1,3,4,5};
    int k = 2;
    int ans = findPairs(nums , k);
    cout<<"Your answer is: "<<ans;
    return 0;
}