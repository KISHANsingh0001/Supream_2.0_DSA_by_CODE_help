#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Solve Using only Recursion
int solveUsingRec(string &a, string &b, int i, int j)
{
    // Base case
    if (i >= a.length() || j >= b.length())
    {
        return 0;
    }
    int ans = 0;
    // case :-1 if both charactors of string a and b are same
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingRec(a, b, i + 1, j + 1);
    }
    // case :-2 if both charactors of string a and b are not same
    else
    {
        ans = 0 + max(solveUsingRec(a, b, i, j + 1), solveUsingRec(a, b, i + 1, j));
    }
    return ans;
}
// Solve Using Recursion + Memoization......................
int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    // Base case
    if (i >= a.length() || j >= b.length())
    {
        return 0;
    }
    // step : 3 if answer is already exist so return answer
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // step 2: store the answer into dp array
    int ans = 0;
    // case :-1 if both charactors of string a and b are same
    if (a[i] == b[i])
    {
        ans = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    // case :-2 if both charactors of string a and b are not same
    else
    {
        ans = 0 + max(solveUsingMem(a, b, i, j + 1, dp), solveUsingMem(a, b, i + 1, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int solveUsingTabu(string &a, string &b)
{
    // Step 1: Create a dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    // Step 2: fill the initial data in dp array according to base case
    // humne vector ko hi 0 elements se initilize kar diya hai kyuki
    // humko last row and last column ko 0 dalna tha
    // step 3: We place the loops according to privious parameters changes
    for (int i = a.length() - 1; i >= 0; --i)
    {
        for (int j = b.length() - 1; j >= 0; --j)
        {
            int ans = 0;
            // case :-1 if both charactors of string a and b are same
            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            // case :-2 if both charactors of string a and b are not same
            else
            {
                ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int solveUsingTabuSO(string &a, string &b)
{
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);
    // column wise traversal karna padega
    for (int j = b.length() - 1; j >= 0; --j)
    {
        for (int i = a.length() - 1; i >= 0; --i)
        {
            int ans = 0;
            // case :-1 if both charactors of string a and b are same
            if (a[i] == b[j])
            {
                ans = 1 + next[i + 1];
            }
            // case :-2 if both charactors of string a and b are not same
            else
            {
                ans = 0 + max(next[i], curr[i + 1]);
            }
            curr[i] = ans;
        }
        // shifting karan bhul jate hai
        next = curr;
    }
    return next[0];
}

// void printdparray(vector<vector<int>> &dp)
// {
//     cout << endl
//          << endl
//          << "printing dp array" << endl;
//     for (int row = 0; row < dp.size(); row++)
//     {
//         for (int col = 0; col < dp[0].size(); col++)
//         {
//             cout << dp[row][col] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl
//          << endl;
// }
int main()
{
    string a = "abc";
    string b = "abcd";
    int i = 0, j = 0;
    // step 1: create a dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));
    // int ans = solveUsingRec(a, b, i, j);
    // int ans = solveUsingMem(a, b, i, j, dp);
    int ans = solveUsingTabuSO(a, b);
    // printdparray(dp);
    cout << "Longest common subsequeces length is: " << ans << endl;
    return 0;
}