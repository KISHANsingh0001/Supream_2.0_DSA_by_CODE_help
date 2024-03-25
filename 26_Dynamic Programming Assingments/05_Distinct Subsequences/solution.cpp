#include <iostream>
#include <vector>
#include <string>
using namespace std;
int solveUsingRec(string &s, string &t, int i, int j)
{
    if (j == t.size())
        return 1;
    if (i == s.size())
        return 0;
    int ans = 0;
    if (s[i] == t[j])
    {
        ans += solveUsingRec(s, t, i + 1, j + 1);
    }
    ans += solveUsingRec(s, t, i + 1, j);
    return ans;
}
int solveUsingMem(string &s, string &t, int i, int j,
                  vector<vector<int>> &dp)
{
    if (j == t.size())
        return 1;
    if (i == s.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s[i] == t[j])
    {
        ans += solveUsingMem(s, t, i + 1, j + 1, dp);
    }
    ans += solveUsingMem(s, t, i + 1, j, dp);
    dp[i][j] = ans;
    return dp[i][j];
}
int solveUsingTabu(string &s, string &t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int j = 0; j <= s.size(); j++)
    {
        dp[j][t.size()] = 1;
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = t.size() - 1; j >= 0; j--)
        {
            long long int ans = 0;
            if (s[i] == t[j])
            {
                ans += dp[i + 1][j + 1];
            }
            ans += dp[i + 1][j];
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    cout<<"NO of subsequences which is equal to t string is: "<<solveUsingTabu(s , t)<<endl;
    return 0;
}