#include <iostream>
#include <vector>
#include<algorithm>
#include <numeric>
using namespace std;
int solveRE(int i, int j, vector<int> &nums)
{
    // base case
    if (i > j)
        return 0;
    if (i == j)
        return nums[i];
    //           do your best ↓  and expect the wrost from the result
    int take_i = nums[i] + min(solveRE(i + 2, j, nums), solveRE(i + 1, j - 1, nums));
    int take_j = nums[j] + min(solveRE(i + 1, j - 1, nums), solveRE(i, j - 2, nums));

    return max(take_i, take_j); // do your best (maximum)
}
int solveTD(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
        return 0;
    if (i == j)
        return nums[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    //           do your best ↓  and expect the wrost from the result
    int take_i = nums[i] + min(solveTD(i + 2, j, nums, dp), solveTD(i + 1, j - 1, nums, dp));
    int take_j = nums[j] + min(solveTD(i + 1, j - 1, nums, dp), solveTD(i, j - 2, nums, dp));

    return dp[i][j] = max(take_i, take_j); // do your best (maximum)
}
int main()
{
    vector<int>nums = {1,5,233,7};
    int total_score = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    //  int player1_score = solveRE(0 , n-1 , nums);
    int player1_score = solveTD(0, n - 1, nums, dp);
    int player2_score = total_score - player1_score;

    //return player1_score >= player2_score ? true : false;
    if(player1_score>=player2_score){
        cout<<"Player 1 has won the game "<<endl;
    }
    else{
        cout<<"player 2 has won the game "<<endl;
    }
    return 0;
}