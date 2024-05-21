#include <iostream>
#include <string>
#include <vector>
using namespace std;
void countZerosAndOnces(vector<string> &strs,
                        vector<pair<int, int>> &numStrs)
{
    for (auto str : strs)
    {
        int zeros = 0, ones = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                ++zeros;
            else
                ++ones;
        }
        numStrs.push_back({zeros, ones});
    }
}
int solveRE(vector<pair<int, int>> &numStrs, int i, int m, int n)
{
    // Base case
    if (i == numStrs.size())
        return 0;
    int zeros = numStrs[i].first;
    int ones = numStrs[i].second;
    int include = 0, exclude = 0;
    if (m - zeros >= 0 && n - ones >= 0)
    {
        include = 1 + solveRE(numStrs, i + 1, m - zeros, n - ones);
    }
    exclude = solveRE(numStrs, i + 1, m, n);
    return max(include, exclude);
}
int solveTD(vector<pair<int, int>> &numStrs, int i, int m, int n, vector<vector<vector<int>>> &dp)
{
    // Base case
    if (i == numStrs.size())
        return 0;
    int zeros = numStrs[i].first;
    int ones = numStrs[i].second;
    if (dp[i][m][n] != -1)
    {
        return dp[i][m][n];
    }
    int include = 0, exclude = 0;
    if (m - zeros >= 0 && n - ones >= 0)
    {
        include = 1 + solveTD(numStrs, i + 1, m - zeros, n - ones, dp);
    }
    exclude = solveTD(numStrs, i + 1, m, n, dp);
    return dp[i][m][n] = max(include, exclude);
}
int solveBU(vector<pair<int, int>> &numStrs, int m, int n)
{
    vector<vector<vector<int>>> dp(
        numStrs.size() + 1,
        vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = numStrs.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int zeros = numStrs[i].first;
                int ones = numStrs[i].second;
                int include = 0, exclude = 0;
                if (j - zeros >= 0 && k - ones >= 0)
                {
                    include = 1 + dp[i + 1][j - zeros][k - ones];
                }
                exclude = dp[i + 1][j][k];
                dp[i][j][k] = max(include, exclude);
            }
        }
    }
    return dp[0][m][n];
}
int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    vector<pair<int, int>> numStrs; // {no. of 0's , no. of 1's}
    countZerosAndOnces(strs, numStrs);
    // cout<<"Maximum size of subset is : "<< solveRE(numStrs , 0 , m , n)<<endl;
    // vector<vector<vector<int>>>dp(strs.size() , vector<vector<int>>(m+1 ,
    // vector<int>(n+1 , -1)));
    //  cout<<"Maximum size of subset is : "<<solveTD(numStrs , 0 , m , n , dp)<<endl;
    cout << "Maximum size of subset is : " << solveBU(numStrs, m, n);
    return 0;
}