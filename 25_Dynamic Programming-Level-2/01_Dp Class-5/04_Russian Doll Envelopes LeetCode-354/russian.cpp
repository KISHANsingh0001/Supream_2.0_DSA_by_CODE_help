class Solution {
public:

    bool check(vector<int>& curr, vector<int>& prev) {
        //curr -> bade wala dabba
        //prev -> chootte wala dabba
        if(prev[0] < curr[0] && prev[1] < curr[1]) {
            return true;
        }
        else {
            return false;
        }
    }

    int solveUsingTabulationSO(vector<vector<int> >& env ) {
        int n = env.size();
        
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);


        for(int curr_index=n-1; curr_index>=0; curr_index--) {
            for(int prev_index=curr_index-1; prev_index >= -1; prev_index--) {

                int include = 0;
                if(prev_index == -1 || check( env[curr_index] , env[prev_index] ) ) {
                    //int heightToAdd = cuboids[curr_index][2];
                    include = 1 + nextRow[curr_index+1];
                }
                int exclude  = 0 + nextRow[prev_index+1];
                currRow[prev_index+1] = max(include, exclude);
            }
            //shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int ans = solveUsingTabulationSO(envelopes);
        return ans;
    }
};