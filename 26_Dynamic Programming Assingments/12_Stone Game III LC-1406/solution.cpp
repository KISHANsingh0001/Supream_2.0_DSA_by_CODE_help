#include <iostream>
#include <vector>
#include <string>
#include<limits.h>
using namespace std;
// Method 1) Solve Using Recurssion
int solveUsingRec(vector<int> &stone, int i)
{
    if (i >= stone.size())
    {
        return 0;
    }
    int result = INT_MIN;
    result = max(result, stone[i] - solveUsingRec(stone, i + 1));
    if (i + 1 < stone.size())
    {
        result = max(result,
                     stone[i] + stone[i + 1] - solveUsingRec(stone, i + 2));
    }
    if (i + 2 < stone.size())
    {
        result = max(result, stone[i] + stone[i + 1] + stone[i + 2] -
                                 solveUsingRec(stone, i + 3));
    }
    return result;
}
// Method 2) Solve using recuursion + memoization
int solveUsingMem(vector<int> &stone, int i, vector<int> &dp)
{
    if (i >= stone.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int result = INT_MIN;
    result = max(result, stone[i] - solveUsingMem(stone, i + 1, dp));
    if (i + 1 < stone.size())
    {
        result = max(result, stone[i] + stone[i + 1] -
                                 solveUsingMem(stone, i + 2, dp));
    }
    if (i + 2 < stone.size())
    {
        result = max(result, stone[i] + stone[i + 1] + stone[i + 2] -
                                 solveUsingMem(stone, i + 3, dp));
    }
    return dp[i] = result;
}
// Method 3) Solve using Tabulation (Bottom up dp)
int solveUsingTabu(vector<int> &stone)
{
    int n = stone.size();
    vector<int> dp(n + 1, 0);
    for (int i = stone.size() - 1; i >= 0; i--)
    {

        int result = INT_MIN;
        result = max(result, stone[i] - dp[i + 1]);
        if (i + 2 <= n)
        {
            result = max(result, stone[i] + stone[i + 1] - dp[i + 2]);
        }

        if (i + 3 <= n)
        {
            result = max(result, stone[i] + stone[i + 1] + stone[i + 2] - dp[i + 3]);
        }

        dp[i] = result;
    }
    return dp[0];
}
int main()
{
    vector<int> stoneValue = {1, 2, 3, 7};
    // vector<int> dp(1000, -1);
    //  int result = solveUsingRec(stoneValue , 0);
    // int result = solveUsingMem(stoneValue, 0, dp);
    int result = solveUsingTabu(stoneValue);
    if (result < 0)
    {
        cout << "Bob has been won";
    }
    else if (result > 0)
    {
        cout << "Alice has been won";
    }
    else
    {
        cout<<"Tie";
    }
    return 0;
}