#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
// Method 1 : SolveUsing Recursion Approch
int solveRE(vector<int> &prices, int i, int buy, int limit)
{
    if (i >= prices.size() || limit == 0)
    {
        return 0;
    }
    int profit = INT_MIN;
    if (buy)
    {
        int buyProfit = -prices[i] + solveRE(prices, i + 1, 0, limit);
        int skipProfit = solveRE(prices, i + 1, 1, limit);
        profit = max(buyProfit, skipProfit);
    }
    else
    {
        // transection compeltes here (limit - 1)
        int sellProfit = prices[i] + solveRE(prices, i + 1, 1, limit - 1);
        int skipProfit = solveRE(prices, i + 1, 0, limit);
        profit = max(sellProfit, skipProfit);
    }
    return profit;
}
// Method 2 : SolveUsing Recursion + Memoization(Top down dp) Approch
int solveTD(vector<int> &prices, int i, int buy, int limit,
            vector<vector<vector<int>>> &dp)
{
    if (i >= prices.size() || limit == 0)
    {
        return 0;
    }
    if (dp[i][buy][limit] != 0)
    {
        return dp[i][buy][limit];
    }
    int profit = INT_MIN;
    if (buy)
    {
        int buyProfit = -prices[i] + solveTD(prices, i + 1, 0, limit, dp);
        int skipProfit = solveTD(prices, i + 1, 1, limit, dp);
        profit = max(buyProfit, skipProfit);
    }
    else
    {
        // transection compeltes here (limit - 1)
        int sellProfit =
            prices[i] + solveTD(prices, i + 1, 1, limit - 1, dp);
        int skipProfit = solveTD(prices, i + 1, 0, limit, dp);
        profit = max(sellProfit, skipProfit);
    }
    return dp[i][buy][limit] = profit;
}
// Method 3 Solveusing Bottom up Approch (Tabulation method)
int solveBU(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {
                int profit = INT_MIN;
                if (buy)
                {
                    int buyProfit = -prices[i] + dp[i + 1][0][limit];
                    int skipProfit = dp[i + 1][1][limit];
                    profit = max(buyProfit, skipProfit);
                }
                else
                {
                    // transection compeltes here (limit - 1)
                    int sellProfit = prices[i] + dp[i + 1][1][limit - 1];
                    int skipProfit = dp[i + 1][0][limit];
                    profit = max(sellProfit, skipProfit);
                }
                dp[i][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    // cout << "Maximum profit is: " << solveRE(prices, 0, 1, 2);
    // cout << "Maximum profit is: " << solveTD(prices, 0, 1, 2, dp);
    cout << "Maximum profit is: " << solveBU(prices);

    return 0;
}