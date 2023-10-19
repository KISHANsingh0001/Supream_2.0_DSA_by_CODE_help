//coin change   not optimize approch>>>>.
class Solution {
public:

    int solve(vector<int>& coins, int amount) {
        //base case
        if(amount == 0 ) {
            return 0;
        }

        if(amount < 0 )
            return INT_MAX;

        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++) {
            int coin = coins[i];

            //current coin ko sir tabhi use krenge 
            //jab uski value <= amount hogi 
            if(coin <= amount) {
                int recAns = solve(coins, amount - coin);
                if(recAns != INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }    
            }
            
        }
        return mini;
    }


    int coinChange(vector<int>& coins, int amount) {
       int ans = solve(coins, amount);

       if(ans == INT_MAX)
        return -1;
        else
        return ans;
        
    }
};