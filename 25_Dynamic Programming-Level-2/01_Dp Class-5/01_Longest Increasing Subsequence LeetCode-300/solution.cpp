#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Method 1: solve using normal recursion
int solveUsingRec(vector<int> &nums, int curr, int prev)
{
    // Base case
    if (curr >= nums.size())
    {
        return 0;
    }
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingRec(nums, curr + 1, curr);
    }
    int exclude = 0 + solveUsingRec(nums, curr + 1, prev);

    return max(include, exclude);
}
// Method 2: solve using Top down Dp(recusion + memoization)
int solveUsingMem(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    // base case
    if (curr >= nums.size())
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev];
    }
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingMem(nums, curr + 1, curr, dp);
    }
    int exclude = 0 + solveUsingMem(nums, curr + 1, prev, dp);
    int ans = max(include, exclude);
    dp[curr][prev + 1] = ans;
    return dp[curr][prev + 1];
}
// Method 3: solve using Bottom up Dp ( Tabulation )          TC :- O(n^2) &  SC:- O(n^2)
int solveUsingTabu(vector<int> &nums)
{
    int n = nums.size();
    // step 1 Create a dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // step 2 fill the initial data into the dp array
    // i observe that ki last vale row column main 0 fill karna hai to maine pura dp array hi
    // zero (0) se initilize kar diya
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }
            int exclude = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}
// Method 3: solve using Bottom up Dp with Space optimization ( Tabulation + Space Optimization )   TC :- O(n^2) &  SC:- O(n^2)
int solveUsingTabuSO(vector<int> &nums)
{
    vector<int> currRow(nums.size() + 1, 0);
    vector<int> nextRow(nums.size() + 1, 0);
    // loop hum row wise chalayege
    for (int curr = nums.size() - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + nextRow[curr + 1];
            }
            int exclude = 0 + nextRow[prev + 1];
            currRow[prev + 1] = max(include, exclude);
        }
        // shifting karna hum bhool jate hai
        nextRow = currRow;
    }
    return nextRow[0];
}
// Method 5: Solve using Binary Search   TC :- O(n Log(n)) &  SC:- O(n)
int solveUsingBS(vector<int> &nums)
{
    vector<int> ans;
    // maintain the initial condition
    ans.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        // push new element when it is greater than of last element of ans
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        // we have to find the just next big index then that in ans vector
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i]; // replace with curr number
        }
    }
    return ans.size();
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // int curr = 0;
    // int prev = -1;
    // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    //  int ans = solveUsingRec(nums, curr, prev);
    // int ans = solveUsingTabuSO(nums);
    int ans = solveUsingBS(nums);
    // printdparray(dp);
    cout << "Longest increasing subsequnces length is : " << ans << endl;
}