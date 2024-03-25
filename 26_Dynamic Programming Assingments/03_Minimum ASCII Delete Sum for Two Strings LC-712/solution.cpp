#include <iostream>
#include<vector>
#include<string>
using namespace std;
int solveUsingRec(string &s1, string &s2, int i, int j)
{
    int cost = 0;
    if (i == s1.size())
    { // if s1 string is being empty
        for (int x = j; x < s2.size(); ++x)
        {
            cost += s2[x];
        }
        return cost;
    }
    else if (j == s2.size())
    { // if s2 string is being empty
        for (int x = i; x < s1.size(); ++x)
        {
            cost += s1[x];
        }
        return cost;
    }
    else if (s1[i] == s2[j])
    {
        cost = solveUsingRec(s1, s2, i + 1, j + 1);
    }
    else
    {
        int cost1 = s1[i] + solveUsingRec(s1, s2, i + 1, j);
        int cost2 = s2[j] + solveUsingRec(s1, s2, i, j + 1);

        cost = min(cost1, cost2);
    }
    return cost;
}
int solveUsingMem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    int cost = 0;
    if (i == s1.size())
    { // if s1 string is being empty
        for (int x = j; x < s2.size(); ++x)
        {
            cost += s2[x];
        }
    }
    else if (j == s2.size())
    { // if s2 string is being empty
        for (int x = i; x < s1.size(); ++x)
        {
            cost += s1[x];
        }
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else if (s1[i] == s2[j])
    {
        cost = solveUsingRec(s1, s2, i + 1, j + 1);
    }
    else
    {
        int cost1 = s1[i] + solveUsingMem(s1, s2, i + 1, j, dp);
        int cost2 = s2[j] + solveUsingMem(s1, s2, i, j + 1, dp);

        cost = min(cost1, cost2);
    }
    dp[i][j] = cost;
    return dp[i][j];
}
int solveUsingTabu(string &s1, string &s2)
{
    // step 1 create a dp array
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // step 2 fill the initial data in to dp array
    for (int i = s1.size() - 1; i >= 0; --i)
    { // s1 string is empty vala case
        dp[i][s2.size()] = s1[i] + dp[i + 1][s2.size()];
    }
    for (int j = s2.size() - 1; j >= 0; j--)
    {
        dp[s1.size()][j] = s2[j] + dp[s1.size()][j + 1];
    }

    for (int i = s1.size() - 1; i >= 0; i--)
    {
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            int cost = 0;
            if (s1[i] == s2[j])
            {
                cost = dp[i + 1][j + 1];
            }
            else
            {
                int cost1 = s1[i] + dp[i + 1][j];
                int cost2 = s2[j] + dp[i][j + 1];
                cost = min(cost1, cost2);
            }
            dp[i][j] = cost;
        }
    }
    return dp[0][0];
}
int main()
{
     string s1 = "sea";
     string s2 = "eat";
     cout<<"Minimum ASCII required to delete is: "<<solveUsingTabu(s1 , s2);
    return 0;
}