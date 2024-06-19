#include <iostream>
#include<vector>
#include<limits.h>
#include<math.h>
using namespace std;
int solveUsingRec(int n)
{
    // Base case
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int ans = INT_MAX;
    int i = 1;
    while (i <= sqrt(n))
    {
        int perfectSqure = i * i;
        int numberOfPerfectSqure = 1 + solveUsingRec(n - perfectSqure);
        if (numberOfPerfectSqure < ans)
        {
            ans = numberOfPerfectSqure;
        }
        ++i;
    }
    return ans;
}

int solveUsingMem(int n, vector<int> &dp)
{
    // Base case
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = INT_MAX;
    int i = 1;
    while (i <= sqrt(n))
    {
        int perfectSqure = i * i;
        int numberOfPerfectSqure = 1 + solveUsingMem(n - perfectSqure, dp);
        if (numberOfPerfectSqure < ans)
        {
            ans = numberOfPerfectSqure;
        }
        ++i;
    }
    dp[n] = ans;
    return dp[n];
}

int solveUsingTabu(int n)
{
    // step 1 : crate a dp array
    vector<int> dp(n + 1, 1);
    // step 2 : fill the initial data into dp array by observing the base
    // dp[0] = 1;
    for (int index = 1; index <= n; index++)
    {
        int ans = INT_MAX;
        int i = 1;
        while (i <= sqrt(index))
        {
            int perfectSqure = i * i;
            int numberOfPerfectSqure = 1 + dp[index - perfectSqure];
            if (numberOfPerfectSqure < ans)
            {
                ans = numberOfPerfectSqure;
            }
            ++i;
        }
        dp[index] = ans;
    }
    return dp[n];
}
int main()
{    
    int n = 12;
    vector<int> dp(n + 1, -1);
    cout<<"Ans is : "<<solveUsingTabu(n)-1;

    return 0;
}