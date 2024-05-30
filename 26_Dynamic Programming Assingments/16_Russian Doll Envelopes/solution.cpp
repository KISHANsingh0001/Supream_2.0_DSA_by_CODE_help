#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Method 1: solve using simple recursion (LIS pattern)
int solveRE(vector<vector<int>> &env, int curr, int prev)
{
    if (curr >= env.size())
    {
        return 0;
    }
    int include = 0;
    if (prev == -1 || env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1])
    {
        include = 1 + solveRE(env, curr + 1, curr);
    }
    int exclude = 0 + solveRE(env, curr + 1, prev);
    return max(include, exclude);
}
// Method 2: solve using Bottom up approch
int solveTD(vector<vector<int>> &env, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr >= env.size())
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    int include = 0;
    if (prev == -1 || env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1])
    {
        include = 1 + solveTD(env, curr + 1, curr, dp);
    }
    int exclude = 0 + solveTD(env, curr + 1, prev, dp);
    return dp[curr][prev + 1] = max(include, exclude);
}
// Method 3: Solve Using Binary search method
static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
int solveOptimaly(vector<vector<int>> &env)
{
    int n = env.size();

    // sorting by height & if we encounter same height
    // sort by descending order of width
    sort(env.begin(), env.end(), cmp);
    vector<int> lis;
    for (int i = 0; i < env.size(); i++)
    {
        int ele = env[i][1];

        int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();

        if (idx >= lis.size())
            lis.push_back(ele);
        else
            lis[idx] = ele;
    }

    return lis.size();
}
int main()
{
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    // sort(envelopes.begin() , envelopes.end());
    //  cout<<" The maximum number of envelopes we can Russian doll "<<solveRE(envelopes , 0 , -1);
    // vector<vector<int>>dp(envelopes.size()+1 , vector<int>(envelopes.size()+1 , -1));
    // cout<<" The maximum number of envelopes we can Russian doll "<<solveTD(envelopes , 0 , -1 , dp);
    cout << "The maximum number of envelopes we can Russian doll:- " << solveOptimaly(envelopes) << endl;
    return 0;
}