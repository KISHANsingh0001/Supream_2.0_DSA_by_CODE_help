class Solution {
public:
    //plain recursion
    int solveUsingRecursion(int n) {
        //base case
        if(n == 0)
            return 0;
        if(n == 1) {
            return 1;
        }
        //recursive relation
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }
    //recursion + memo
    int solveUsingMemoisation(int n, vector<int>& dp) {
        //base case
        if(n == 0)
            return 0;
        if(n == 1) {
            return 1;
        }
        //step3: check if already exist , then return ans
        if(dp[n] != -1) {
            return dp[n];
        }
        //recursive relation
        //step2: store ans in dp array
        dp[n] = solveUsingMemoisation(n-1,dp) + solveUsingMemoisation(n-2, dp);
        return dp[n];
    }
    //tabulation method
    int solveUsingTabulation(int n) {
        //step1: create dp array
        vector<int> dp(n+1, -1);
        //step2: analyse base case and fill dp array
        dp[0] = 0;
        if(n == 0) {
            return 0;
        }
        dp[1] = 1;
        //step3: fill the remaingin dp array
        //array size = n+1
        //index move from 0 to n
        //0 and 1 index ko already fill krlia h
        //2 index se n index tak abhi filled nahi h
        for(int index = 2; index<=n; index++) {
            //copy paste karo recursive logic ko
            //repalce recursive calls  with dp array
            //make sure dp array is using looping variable
            dp[index] = dp[index-1] + dp[index-2];
        }
        //return ans;
        return dp[n];
    }

    int solveUsingTabulationSpaceOptimised(int n) {
        int prev = 0;
        if(n == 0) {
            return 0;
        }
        int curr = 1;
        if(n == 1) {
            return 1;
        }
        int ans;
        for(int index = 2; index<=n; index++) {
            ans = curr + prev;
            // prev and curr ko ek step aage move krna
            prev = curr;
            curr = ans;
        }
        //return ans;
        return ans;
    }
    int fib(int n) {
        // int ans = solveUsingRecursion(n);
        // return ans;

        //step1: create dp array
        // vector<int> dp(n+1, -1);
        // int ans = solveUsingMemoisation(n, dp);
        // return ans;

        // int ans = solveUsingTabulation(n);
        // return ans;
        return solveUsingTabulationSpaceOptimised(n);
    }
};
