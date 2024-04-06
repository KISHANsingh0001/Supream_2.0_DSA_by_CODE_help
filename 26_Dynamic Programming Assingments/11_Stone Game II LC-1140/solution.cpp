#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
// Method 1 Solve Using Simple Recurssion
int solve(vector<int> &piles, int i, int m, bool alice)
{
    if (i == piles.size())
        return 0;
    // true for alice turn and false for Bob turn
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;

    for (int x = 1; x <= 2 * m; x++)
    {
        if (i + x - 1 >= piles.size())
            break;
        total += piles[i + x - 1];
        if (alice)
            ans = max(ans, total + solve(piles, i + x, max(x, m), !alice));
        else
            ans = min(ans, solve(piles, i + x, max(x, m), !alice));
    }
    return ans;
}
// Method 2 : solve using recurssion + Memoization (Top Down Dp)
int solveTD(vector<int> &piles, int i, int m, bool alice, vector<vector<vector<int>>> &dp)
{
    if (i == piles.size())
        return 0;

    if (dp[i][m][alice] != -1)
        return dp[i][m][alice];
    // true for alice turn and false for Bob turn
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;

    for (int x = 1; x <= 2 * m; x++)
    {
        if (i + x - 1 >= piles.size())
            break;
        total += piles[i + x - 1];
        if (alice)
            ans = max(ans,
                      total + solveTD(piles, i + x, max(x, m), !alice, dp));
        else
            ans = min(ans, solveTD(piles, i + x, max(x, m), !alice, dp));
    }
    return dp[i][m][alice] = ans;
}
// Method 3: Solve Using tabulation (Bottom Up DP)
int solveBU(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, 0)));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int m = n; m >= 1; --m)
        {
            for (int alice = 0; alice <= 1; alice++)
            {
                int ans = alice ? INT_MIN : INT_MAX;
                int total = 0;

                for (int x = 1; x <= 2 * m; x++)
                {
                    if (i + x - 1 >= piles.size())
                        break;
                    total += piles[i + x - 1];
                    if (alice)
                        ans = max(ans, total + dp[i + x][max(x, m)][!alice]);
                    else
                        ans = min(ans, dp[i + x][max(x, m)][!alice]);
                }
                dp[i][m][alice] = ans;
            }
        }
    }
    return dp[0][1][1];
}
int main()
{
    vector<int> piles = {2, 7, 9, 4, 4};
    vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
    // cout<<solve(piles , 0 , 1 , true);
    // cout<<solveTD(piles, 0, 1, true, dp);
    cout<<solveBU(piles);
    return 0;
}