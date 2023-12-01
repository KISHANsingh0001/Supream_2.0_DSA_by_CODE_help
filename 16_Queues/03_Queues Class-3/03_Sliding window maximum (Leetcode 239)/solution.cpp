
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> q; // stroes the max elements index.
      vector<int> ans; // stroes the max element in every k window

      // step 1: process the k window
      for(int i = 0 ; i<k ; i++){
          int element = nums[i];

          while(!q.empty() && element > nums[q.back()]){
              q.pop_back();
          }
          q.push_back(i);
      }  

      // step 2: process the remaining window 
      for(int i=k ; i<nums.size() ; i++) {
          // purani vali window ka ans store karwa lo
          ans.push_back(nums[q.front()]);
         // remove the out of range index
         if(!q.empty() && i - q.front() >= k){
             q.pop_front();
         }
         while(!q.empty() && nums[i] > nums[q.back()]){
             q.pop_back();
         }
         q.push_back(i);
      }

      // step 3: last window ka ans stroe kar lo
       ans.push_back(nums[q.front()]);
       return ans;
    }
int main()
{
    vector<int>nums = {1,3,4,1,2,3,6};
    int k = 3 ; // means size of the window.
    vector<int>ans = maxSlidingWindow(nums , k);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}