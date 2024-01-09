class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount) {
        //base case
        if(amount == 0) {
            return 0;
        }

        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            //find ans using ith coin
            //call recursion only for valid amounts i.e. >=0  wale amounts
            if(amount - coins[i] >= 0) {
                int recursionKaAns = solveUsingRecursion(coins, amount - coins[i]);
                //if a valid answeer
                if(recursionKaAns != INT_MAX) {
                    //considering uage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini  = min(mini, ans);
                }
            }
        }
        return mini;
    }
    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
        //base case
        if(amount == 0) {
            return 0;
        }
        //already ans exist
        if(dp[amount] != -1) {
            return dp[amount];
        }
        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            //find ans using ith coin
            //call recursion only for valid amounts i.e. >=0  wale amounts
            if(amount - coins[i] >= 0) {
                int recursionKaAns = solveUsingMem(coins, amount - coins[i], dp);
                //if a valid answeer
                if(recursionKaAns != INT_MAX) {
                    //considering uage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini  = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int solveUsingTabulation(vector<int>& coins, int amount) {
        //step1: done
        int n = amount;
        vector<int> dp(n+1, INT_MAX);
        //step2: base case analyse
        dp[0] = 0;
        //for loop
        for( int value = 1; value<=amount; value++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
            
                if(value - coins[i] >= 0) {
                    int recursionKaAns = dp[value - coins[i] ];
                    
                    if(recursionKaAns != INT_MAX) {
                        
                        int ans = 1 + recursionKaAns;
                        mini  = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans =  solveUsingRecursion(coins, amount);
        //int n = amount;
        //vector<int> dp(n+1, -1);
        int ans = solveUsingTabulation(coins, amount);
        if(ans == INT_MAX)
            return -1;
        else {
            return ans;
        }
    }
};
