// Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color.

// Input : n = 2 k = 4
// Output : 16
// Explanation: We have 4 colors and 2 posts.
// Ways when both posts have same color : 4 
// Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12

// Input : n = 3 k = 2
// Output : 6
#include <iostream>
#include<vector>
using namespace std;
// solution using recursion
int solveUsingRecursion(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    int ans = (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
    return ans;
}
// solution using top down dp(recursion+memoization)
int solveUsingMem(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    // already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp)) * (k - 1);
    return dp[n];
}
// solution using bottom up dp(Tabulation method)
int solveUsingTabulation(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = k + k * (k - 1);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}
// solution using bottom up dp(Tabulation method) with some space optimization
int solveUsingTabulationSO(int n, int k)
{
    // vector<int> dp(n+1, -1);
    int prev2 = k;
    int prev1 = k + k * (k - 1);
    if (n == 1)
    {
        return prev2;
    }
    if (n == 2)
    {
        return prev1;
    }
    int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        // shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
    int n = 3;
    int k = 3;
    vector<int>dp(n+1 , -1);
    int ans = solveUsingMem(n, k,dp);
    cout << "Number of possible ways to paint fences is : " << ans << endl;
    return 0;
}