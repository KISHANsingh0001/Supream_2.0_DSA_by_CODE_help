#include <iostream>
#include <vector>
#include <string>
#include<limits.h>
using namespace std;
int solveUsingRec(vector<int> &nums, int start, int end)
{
    // Base case
    if (start > end)
        return 0;
    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] +
                               solveUsingRec(nums, start, i - 1) +
                               solveUsingRec(nums, i + 1, end));
    }
    return coins;
}
int solveUsingMem(vector<int> &nums, int start, int end,
                  vector<vector<int>> &dp)
{
    // Base case
    if (start > end)
        return 0;

    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] +
                               solveUsingMem(nums, start, i - 1, dp) +
                               solveUsingMem(nums, i + 1, end, dp));
    }

    return dp[start][end] = coins;
}
int solveUsingTabu(vector<int> &nums)
{

    vector<vector<int>> dp(nums.size(),
                           vector<int>(nums.size(), 0));

    for (int start = nums.size() - 2; start >= 1; start--)
    {
        for (int end = 1; end <= nums.size() - 2; end++)
        {
            if (start > end)
                continue;

            int coins = INT_MIN;
            for (int i = start; i <= end; i++)
            {
                coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + dp[start][i - 1] + dp[i + 1][end]);
            }
            dp[start][end] = coins;
        }
    }
    return dp[1][nums.size() - 2];
}
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    vector<vector<int>> dp(nums.size() + 2,
                           vector<int>(nums.size() + 2, -1));
    int start = 1;
    int end = nums.size() - 2;
    // return solveUsingRec(nums , start , end);
    // return solveUsingMem(nums, start, end, dp);
    return solveUsingTabu(nums);
}
int main()
{
    vector<int>nums = {3,1,5,8};
    cout<<"maximum coins you can collect by bursting the balloons wisely "<<maxCoins(nums);
    return 0;
}