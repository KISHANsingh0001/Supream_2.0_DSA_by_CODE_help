#include <iostream>
using namespace std;
// recursion + memo
int solveUsingMemoisation(int n, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;
    if (n == 1)
    {
        return 1;
    }
    // step3: check if already exist , then return ans
    if (dp[n] != -1)
    {
        return dp[n];
    }
    // recursive relation
    // step2: store ans in dp array
    dp[n] = solveUsingMemoisation(n - 1, dp) + solveUsingMemoisation(n - 2, dp);
    return dp[n];
}
int main()
{
    int n = 6;
    cout << n << "'th fibonacci number is: " << solveUsingRecursion(n);
    return 0;
}