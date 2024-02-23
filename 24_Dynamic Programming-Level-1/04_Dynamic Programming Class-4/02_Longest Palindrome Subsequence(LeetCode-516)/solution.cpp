
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solveUsingRec(string &a, string &b, int i, int j)
{
    // base case
    if (i >= a.length() || j >= b.length())
    {
        return 0;
    }
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingRec(a, b, i + 1, j + 1);
    }
    else
    {
        ans = 0 + max(solveUsingRec(a, b, i + 1, j), solveUsingRec(a, b, i, j + 1));
    }
    return ans;
}
int solveUsingMem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    // Base case
    if (i >= a.length() || j >= b.length())
    {
        return 0;
    }
    // step : 3 if answer is already exist so return answer
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }

    // step 2: store the answer into dp array
    int ans = 0;
    // case :-1 if both charactors of string a and b are same
    if (a[i] == b[j])
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
int solveUsingTabuSO(string a, string b)
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
int main()
{
    string a = "bbbab"; // orignal string
    string b = a;       // reversed string
    reverse(b.begin(), b.end());
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    int i = 0, j = 0;
    // int ans = solveUsingTabuSO(text2 , text1);
    int ans = solveUsingTabu(a, b);
    cout << "Longest palindromic subsequence is: " << ans << endl;

    return 0;
}