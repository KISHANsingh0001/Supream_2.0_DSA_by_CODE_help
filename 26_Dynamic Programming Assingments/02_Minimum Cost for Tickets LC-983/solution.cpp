#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingRec(vector<int> &days, vector<int> &costs, int i)
{
    // Base case
    if (i >= days.size())
    {
        return 0;
    }
    // soloution for 1 case;
    // 1 day pass teken
    int cost1 = costs[0] + solveUsingRec(days, costs, i + 1);

    // 7 days pass is taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + solveUsingRec(days, costs, j);

    // 30 days pass is taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + solveUsingRec(days, costs, j);

    return min(cost1, min(cost7, cost30));
}
//   Top down dp
int solveUsingMem(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
{
    // Base case
    if (i >= days.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    // soloution for 1 case;
    // 1 day pass teken
    int cost1 = costs[0] + solveUsingMem(days, costs, i + 1, dp);

    // 7 days pass is taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + solveUsingMem(days, costs, j, dp);

    // 30 days pass is taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + solveUsingMem(days, costs, j, dp);

    dp[i] = min(cost1, min(cost7, cost30));
    return dp[i];
}

// Bottom up Dp

int solveUsingTabu(vector<int> &days, vector<int> &costs)
{
    // step1 create a dp array
    // step2 fill the initial data into dp array
    vector<int> dp(days.size() + 10, 0);
    for (int i = days.size() - 1; i >= 0; i--)
    {
        int cost1 = costs[0] + dp[i + 1];

        // 7 days pass is taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + dp[j];

        // 30 days pass is taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + dp[j];

        dp[i] = min(cost1, min(cost7, cost30));
    }
    return dp[0];
}
int main()
{
    vector<int> days = {1,4,6,7,8,20};
    vector<int>costs = {2,7,15};
    // create a dp array
    vector<int> dp(days.size() + 1, -1);
    // int ans =  solveUsingRec(days , costs , 0);
    // return solveUsingMem(days, costs, 0, dp);
    cout<<" Minimum number of dollars you need to travel: "<< solveUsingTabu(days, costs)<<endl;

    return 0;
}