#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
// #define INT_MAX 2147483647
// int solveUsingRec(vector<int> &coins, int amount)
// {
//     // Base case
//     if (amount < 0)
//     {
//         return INT_MAX;
//     }
//     if (amount == 0)
//     {
//         return 0;
//     }
//     int mini = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         int coin = coins[i];
//         if (coin <= amount)
//         {
//             int recursionAns = solveUsingRec(coins, amount - coin);
//             if (recursionAns != INT_MAX)
//             {
//                 int ans = 1 + recursionAns;
//                 mini = min(mini, ans);
//             }
//         }
//     }
//     return mini;
// }
// int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp)
// {
//     if (amount == 0)
//     {
//         return 0;
//     }
//     if (amount < 0)
//     {
//         return INT_MAX;
//     }
//     if (dp[amount] != -1)
//     {
//         return dp[amount];
//     }
//     int mini = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         // curr coin
//         int coin = coins[i];
//         // yadi hamar coin vo amount se chota hai ya equal hai to hi use karge
//         if (coin <= amount)
//         {
//             int recursionAns = solveUsingMem(coins, amount - coin, dp);
//             if (recursionAns != INT_MAX)
//             {
//                 int ans = 1 + recursionAns;
//                 mini = min(mini, ans);
//             }
//         }
//     }
//     dp[amount] = mini;
//     return dp[amount];
// }
int solveUsingTabulation(vector<int> &coins, int amount, vector<int> &dp)
{
    // step 1 : create dp array
    // vector<int> dp(amount + 1, INT_MAX);
    // step 2: analayese the base case
    dp[0] = 0;
    for (int value = 1; value <= amount; value++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            // curr coin
            int coin = coins[i];
            // yadi hamar coin vo amount se chota hai ya equal hai to hi use karge
            if (coin <= value)
            {
                int recursionAns = dp[value - coin];
                if (recursionAns != INT_MAX)
                {
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[value] = mini;
    }
    return dp[amount];
}
int main()
{
    vector<int> coins = {6, 8, 5};
    int amount = 11;
    vector<int> dp(amount + 1, -1);

    int ans = solveUsingTabulation(coins, amount, dp);
    // for (auto it : dp)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    if (ans == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << "Coins required is: " << ans << endl;
    }
    return 0;
}