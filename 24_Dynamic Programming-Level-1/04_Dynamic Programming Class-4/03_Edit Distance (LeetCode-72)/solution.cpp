#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//  First Method : solve using recursion but it gives TLE...........
int solveUsingRec(string &a, string &b, int i, int j)
{
    // Base case
    if (i == a.length())
    {
        return b.length() - j;
    }
    if (j == b.length())
    {
        return a.length() - i;
    }
    // Charactor Matched vala case
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 0 + solveUsingRec(a, b, i + 1, j + 1);
    }
    else
    {
        // Does not match vala case
        // we count 3 operations
        // 1)Replace
        int replaceOp = 1 + solveUsingRec(a, b, i + 1, j + 1);
        // 2)Delete
        int deleteOp = 1 + solveUsingRec(a, b, i + 1, j);
        // 2)insert
        int insertOp = 1 + solveUsingRec(a, b, i, j + 1);
        // Find out the minimum operation
        ans = min(insertOp, min(deleteOp, replaceOp));
    }
    return ans;
}
//  Second Method : solve using Top down DP
//  (Recursion+Memoization)..............
int solveUsingMem(string &a, string &b, int i, int j,
                  vector<vector<int>> &dp)
{
    // Base case
    if (i == a.length())
    {
        return b.length() - j;
    }
    if (j == b.length())
    {
        return a.length() - i;
    }
    // Step 3: If ans is alradey exist then return ans
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // Step 2: Store the answer into the dp array
    // Charactor Matched vala case
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 0 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        // Does not match vala case
        // we count 3 operations
        // 1)Replace
        int replaceOp = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        // 2)Delete
        int deleteOp = 1 + solveUsingMem(a, b, i + 1, j, dp);
        // 2)insert
        int insertOp = 1 + solveUsingRec(a, b, i, j + 1);
        // Find out the minimum operation
        ans = min(insertOp, min(deleteOp, replaceOp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
//  Thired Method : solve using Bottom up DP (Tabulation Method)..........
int solveUsingTabu(string &a, string &b)
{
    // Step 1 : Create a dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));
    // Step2 : Fill the initial data into dp array according to base case
    for (int col = 0; col <= b.length(); col++)
    {
        dp[a.length()][col] = b.length() - col;
    }
    for (int row = 0; row <= a.length(); row++)
    {
        dp[row][b.length()] = a.length() - row;
    }
    for (int row = a.length() - 1; row >= 0; row--)
    {
        for (int col = b.length() - 1; col >= 0; col--)
        {
            int ans = 0;
            if (a[row] == b[col])
            {
                ans = 0 + dp[row + 1][col + 1];
            }
            else
            {
                // Does not match vala case
                // we count 3 operations
                // 1)Replace
                int replaceOp = 1 + dp[row + 1][col + 1];
                // 2)Delete
                int deleteOp = 1 + dp[row + 1][col];
                // 2)insert
                int insertOp = 1 + dp[row][col + 1];
                // Find out the minimum operation
                ans = min(insertOp, min(deleteOp, replaceOp));
            }
            dp[row][col] = ans;
        }
    }
    return dp[0][0];
}
int main()
{
    string word1 = "horse";
    string word2 = "ros";
    int i = 0;
    int j = 0;
    // step 1 : Create a dp array
    // vector<vector<int>> dp(word1.length() + 1,vector<int>(word2.length() + 1, -1));
    // int ans = solveUsingRec(word1 , word2 , i , j);
    int ans = solveUsingTabu(word1, word2);
    cout<<"minimum number of operations required is : "<<ans<<endl;
    return 0;
}