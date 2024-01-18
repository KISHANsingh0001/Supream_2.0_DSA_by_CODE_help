#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(vector<int>& arr, map< pair<int,int>, int >& maxi, int s, int e) {
        //base case
        if(s > e) {
            return 0;
        }
        if(s == e) {
            return 0;
        } 

        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            //i is used here for partitioning
            ans = min(ans, (maxi[{s, i}] * maxi[{i+1,e}]) + 
                            solveUsingRecursion(arr,maxi, s, i) + 
                            solveUsingRecursion(arr,maxi, i+1, e) );
        }
        return ans;
    }

    int solveUsingMem(vector<int>& arr, map< pair<int,int>, int >& maxi, int s, int e,vector<vector<int> >& dp) {
        //base case
        if(s > e) {
            return 0;
        }
        if(s == e) {
            return 0;
        } 
        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i=s; i<e; i++) {
            //i is used here for partitioning
            ans = min(ans, (maxi[{s, i}] * maxi[{i+1,e}]) + 
                            solveUsingMem(arr,maxi, s, i,dp) + 
                            solveUsingMem(arr,maxi, i+1, e, dp) );
        }
        dp[s][e] = ans;
        return dp[s][e];
    }

    int solveUsingTabulation(vector<int>& arr,map< pair<int,int>, int >& maxi) {
        int n = arr.size();
        vector<vector<int> > dp(n+2, vector<int>(n+1, 0));

        for(int s_index=n; s_index>=0; s_index--) {
            for(int e_index=0; e_index<=n-1; e_index++) {
                if(s_index >= e_index) {
                    continue;
                }
                int ans = INT_MAX;
                for(int i=s_index; i<e_index; i++) {
                    //i is used here for partitioning
                    ans = min(ans, (maxi[{s_index, i}] * maxi[{i+1,e_index}]) + dp[s_index][i] +  dp[i+1][e_index] );
                }
                dp[s_index][e_index] = ans;
            }
        }
        
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        //pre computation
        map< pair<int,int>, int > maxi;
        for(int i=0; i<arr.size(); i++) {
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        int n = arr.size();
        int start = 0;
        int end = n-1;
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingTabulation(arr,maxi);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int>arr = {6,2,4};
    int ans = s.mctFromLeafValues(arr);
    cout<<"the smallest possible sum of the values of each non-leaf node. It is: "<<ans<<endl;
    return 0;
}