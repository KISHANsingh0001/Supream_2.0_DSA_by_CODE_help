#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
int solveUsingRec(vector<int> &prices, int i, int buy)
{
    if (i >= prices.size())
        return 0;
    int profit = INT_MIN;
    if (buy)
    { // Buy karke dekho
        int buyProfit = solveUsingRec(prices, i + 1, 0) - prices[i];
        int skipProfit =
            solveUsingRec(prices, i + 1, 1); // skip karke dekho
        profit = max(buyProfit, skipProfit);
    }
    else
    { // sell karke dekho
        int sellProfit = solveUsingRec(prices, i + 1, 1) + prices[i];
        int skipProfit =
            solveUsingRec(prices, i + 1, 0); // skip karke dekho
        profit = max(sellProfit, skipProfit);
    }
    return profit;
}
int solveUsingMem(vector<int> &prices, int i, int buy,
                  vector<vector<int>> &dp)
{
    if (i >= prices.size())
        return 0;
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }
    int profit = INT_MIN;
    if (buy)
    { // Buy karke dekho
        int buyProfit = solveUsingMem(prices, i + 1, 0, dp) - prices[i];
        int skipProfit =
            solveUsingMem(prices, i + 1, 1, dp); // skip karke dekho
        profit = max(buyProfit, skipProfit);
    }
    else
    { // sell karke dekho
        int sellProfit = solveUsingMem(prices, i + 1, 1, dp) + prices[i];
        int skipProfit =
            solveUsingMem(prices, i + 1, 0, dp); // skip karke dekho
        profit = max(sellProfit, skipProfit);
    }
    return dp[i][buy] = profit;
}
int solveUsingTabu(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    int profit = INT_MIN;
    for (int i = prices.size() - 1; i >= 0; --i)
    {
        for (int buy = 0; buy < 2; buy++)
        {

            if (buy)
            { // Buy karke dekho
                int buyProfit = dp[i + 1][0] - prices[i];
                int skipProfit = dp[i + 1][1]; // skip karke dekho
                profit = max(buyProfit, skipProfit);
            }
            else
            { // sell karke dekho
                int sellProfit = dp[i + 1][1] + prices[i];
                int skipProfit = dp[i + 1][0]; // skip karke dekho
                profit = max(sellProfit, skipProfit);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    // cout<<"Maximum profit "<<solveUsingRec(prices, 0, 1)<<endl;
    cout << "Maximum profit " << solveUsingTabu(prices);

    return 0;
}