#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(int start, int end ) {
        //base case
        if(start >= end) {
            return 0;
        }

        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
            ans = min(ans, i + max(solveUsingRecursion(start, i-1), solveUsingRecursion(i+1, end)));
        }
        return ans; 
    }
    int solveUsingMem(int start, int end,vector<vector<int> >& dp ) {
        //base case
        if(start >= end) {
            return 0;
        }

        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i=start; i<=end; i++) {
            ans = min(ans, i + max(solveUsingMem(start, i-1,dp), solveUsingMem(i+1, end,dp)));
        }
        dp[start][end] = ans;
        return dp[start][end]; 
    }

    int solveUsingTabulation(int n) {
        vector<vector<int> > dp(n+2, vector<int>(n+1, 0));
        for(int start_index = n-1; start_index>=1; start_index--) {
            for(int end_index = 1; end_index<=n; end_index++) {

                if(start_index >= end_index) {
                    //invalid range
                    continue;
                }
                int ans = INT_MAX;
                for(int i=start_index; i<=end_index; i++) {
                    ans = min(ans, i + max(dp[start_index][i-1], dp[i+1][end_index] ) );
                }
                dp[start_index][end_index] = ans;
                
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingTabulation(n);
        return ans;
    }
};
int main()
{
    Solution s;
    int input = 10;
    int ans = s.getMoneyAmount(input);
    cout<<"the minimum amount of money you need to guarantee a win regardless "<<ans<<endl;
    return 0;
}