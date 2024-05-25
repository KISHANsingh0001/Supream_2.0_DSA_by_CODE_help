#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n;
int solveUsingRec(vector<int> &satisfaction, int i, int time)
{
    // Base case
    if (i >= n)
        return 0;
    int include = satisfaction[i] * time + // cook karke dekhliya hai
                  solveUsingRec(satisfaction, i + 1, time + 1);
    int exclude = solveUsingRec(satisfaction, i + 1, time); // cook nahi kiya(dicard the dish)
    return max(include, exclude);
}

int solveTD(vector<int> &satisfaction, int i, int time,
            vector<vector<int>> &dp)
{
    // Base case
    if (i >= n)
        return 0;
    if (dp[i][time] != -1)
        return dp[i][time];

    int include =
        satisfaction[i] * time + solveTD(satisfaction, i + 1, time + 1, dp);
    int exclude = solveTD(satisfaction, i + 1, time, dp);
    return max(include, exclude);
}

int solveBU(vector<int> &satisfaction)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int time = n; time > 0; time--)
        {
            int include = satisfaction[i] * time + dp[i + 1][time + 1];
            int exclude = dp[i + 1][time];
            dp[i][time] = max(include, exclude);
        }
    }
    return dp[0][1];
}

int main()
{
        vector<int>satisfaction = {-1,-8,0,5,-9};
        n = satisfaction.size();
        int i = 0, time = 1;
        sort(begin(satisfaction), end(satisfaction));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // cout<<"maximum sum of like-time coefficient is: "<<solveUsingRec(satisfaction , n , i , time);
        // cout<<"maximum sum of like-time coefficient is: "<<solveTD(satisfaction, i, time, dp);
        cout<<"maximum sum of like-time coefficient is: "<<solveBU(satisfaction)<<endl;

    return 0;
}