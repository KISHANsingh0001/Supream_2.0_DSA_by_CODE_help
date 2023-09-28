// #method number 2 Two Pointer Approch 
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

    int findPairs(vector<int>& nums, int k)
   {
     // # TWO POINTER APPROCH
            sort(nums.begin() , nums.end());
            set<pair<int , int>>ans;
            int i = 0 , j = 1;
            while(j<nums.size()){
                int diff = nums[j] - nums[i];
                if(diff == k){
                    ans.insert({nums[i] , nums[j]});
                    ++i;++j;
                }
                else if(diff > k){ 
                    i++;
                }
                else{  // if differance less then k then we increment the j pointer
                      // because we need grater value
                    j++;
                }
                if(i==j) j++;
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