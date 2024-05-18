#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solveRE(vector<int> &nums, int target, int i)
{
    if (i == nums.size())
        return target == 0 ? 1 : 0;
    int minus = solveRE(nums, target - nums[i], i + 1);
    int plus = solveRE(nums, target + nums[i], i + 1);

    return minus + plus;
}
int solveTD(vector<int> &nums, int target, int i, map<pair<int, int>, int> &mp)
{
    if (i == nums.size())
        return target == 0 ? 1 : 0;
    if (mp.find({target, i}) != mp.end())
    {
        return mp[{target, i}];
    }
    int minus = solveTD(nums, target - nums[i], i + 1, mp);
    int plus = solveTD(nums, target + nums[i], i + 1, mp);

    return mp[{target, i}] = minus + plus;
}
int solveBU(vector<int> &nums, int target)
{
    map<pair<int, int>, int> dp;
    dp[{nums.size(), 0}] = 1;
    int total = 0;
    for (auto num : nums)
        total += num;

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        for (int sum = -total; sum <= total; ++sum)
        {
            int minus = dp.find({i + 1, sum - nums[i]}) != dp.end() ? dp[{i + 1, sum - nums[i]}] : 0;
            int plus = dp.find({i + 1, sum + nums[i]}) != dp.end() ? dp[{i + 1, sum + nums[i]}] : 0;
            dp[{i, sum}] = minus + plus;
        }
    }
    return dp[{0, target}];
}
int main()
{
        vector<int> nums = {1,1,1,1,1};
        int target = 3;
       //map<pair<int,int> , int > mp;
       //cout<<"Number of different ways : " << solveTD(nums , target , 0 , mp);
       //cout<<"Number of different ways : " << solveRE(nums , target , 0);
       cout<<"Number of different ways : " << solveBU(nums , target);
    return 0;
}