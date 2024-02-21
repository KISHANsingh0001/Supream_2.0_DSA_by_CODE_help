
#include <iostream>
#include<vector>
using namespace std;
int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n)
{
    // base case
    if (index >= n)
    {
        return 0;
    }

    // inc / exc
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRecursion(capacity - wt[index], wt, profit, index + 1, n);
    }
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index + 1, n);
    int ans = max(include, exclude);
    return ans;
}
void printdparray(vector<vector<int> >& dp) {
	cout << endl << endl << "printing dp array" << endl;
	for(int row=0; row<dp.size(); row++) {
		for(int col=0; col<dp[0].size(); col++) {
			cout << dp[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{
    // base case
    if (index >= n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }

    // already exists
    if (dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }

    // inc / exc
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }
    int exclude = 0 + solveUsingMem(capacity, wt, profit, index + 1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}

int solveUsingTabulation(int capacity, int wt[], int profit[], int n)
{
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    for (int row = 0; row <= capacity; row++)
    {
        dp[row][n] = 0;
    }

    for (int row = 0; row <= capacity; row++)
    {
        for (int col = n - 1; col >= 0; col--)
        {
            int include = 0;
            if (wt[col] <= row)
            {
                include = profit[col] + dp[row - wt[col]][col + 1];
            }
            int exclude = 0 + dp[row][col + 1];
            dp[row][col] = max(include, exclude);
        }
    }

    printdparray(dp); 
    return dp[capacity][0];
}

int solveUsingTabulationSO(int capacity, int wt[], int profit[], int n)
{
    vector<int> next(capacity + 1, 0);
    vector<int> curr(capacity + 1, -1);

    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row <= capacity; row++)
        {
            int include = 0;
            if (wt[col] <= row)
            {
                include = profit[col] + next[row - wt[col]];
            }
            int exclude = 0 + next[row];
            curr[row] = max(include, exclude);
        }
        // shifting
        next = curr;
    }
    return curr[capacity];
}
int main()
{
    int capacity = 6;
    int wt[] = {1, 2, 3};
    int profit[] = {10, 15, 40};
     int index = 0;
    int n = 3;

    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    int ans = solveUsingTabulation(capacity, wt, profit,n);
    //printdparray(dp);
    //int ans = solveUsingTabulationSO2(capacity, wt, profit, n);
    cout << "max Profit: " << ans << endl;

    return 0;
}