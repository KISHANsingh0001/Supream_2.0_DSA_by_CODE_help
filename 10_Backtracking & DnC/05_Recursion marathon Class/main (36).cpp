#include <iostream>
#include<vector>
using namespace std;
// count derrangments
int solve(int n) {

	//base case
	if(n == 1) {
		return 0;
	}
	if(n == 2) {
		return 1;
	}

	int ans = (n-1) * (solve(n-1) + solve(n-2));
	return ans;
}
//painting fence algo
int getPaintWays(int n, int k ) {
	//base case
	if(n == 1) {
		return k;
	}
	if(n == 2) {
		return k + k*(k-1);
	}

	int ans = (k-1) * (getPaintWays(n-1,k) + getPaintWays(n-2,k));
	return ans;
}

int main() {

	// int n = 4;
	// cout << solve(n) << endl;


	int n = 3;
	int k = 3;
	int ans = getPaintWays(n,k);
	cout << ans << endl;
	return 0;
}

//House Robber 1:

class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        //base case
        if(s > e) {
            return 0;
        }
        //include
        int option1 = nums[s] + solve(nums, s+2, e);
        //exclude
        int option2 = 0 + solve(nums, s+1, e);
        
        int ans = max(option1, option2);
        return ans;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = solve(nums, s, e);
        return ans;

        
    }
};

//House Robber 2:
class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        //base case
        if(s > e ) {
            return 0;
        }

        //chori karlo -> ith index pr
        int option1 = nums[s] + solve(nums, s+2, e);

        //chori mat karo  -> ith index pr
        int option2 = 0 + solve(nums, s+1, e);

        int finalAns = max(option1, option2);
        return finalAns;
    }
    
    int rob(vector<int>& nums) {

        int n = nums.size();
        //single element - yha pr maine glti ki thi
        if(n == 1) {
            return nums[0];
        }
        int option1 = solve(nums,0, n-2);
        int option2 = solve(nums, 1, n-1);

        int ans = max(option1, option2);
        return ans;
        
    }
};

//Edit Distance
class Solution {
public:
    int solve(string& a, string& b, int i, int j) {
        //base case
        if(i >= a.length()) {
            //word1 wali string end hogyi
            //yani word1 ki length may be word 2 se choti h 
            return b.length() - j;
        }
        if(j >= b.length()) {
            //word 2 end hogya
            //yaaani word 1 ki length may be greater than word2 hai
            return a.length() - i;
        }
        int ans = 0;

        if(a[i] == b[j]) {
            //match
            ans = 0 + solve(a, b, i+1, j+1);
        }
        else {
            //not match
            //operation perform karo
            //insert
            int option1 = 1 + solve(a,b, i, j+1);
            //remove
            int option2 = 1 + solve(a,b,i+1, j);
            //replace
            int option3 = 1 + solve(a,b,i+1, j+1);
            ans = min(option1, min(option2, option3));
        }
        return ans;

    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = solve(word1, word2, i, j);
        return ans;
    }
};

//Maximal Square:

class Solution {
public: 
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
        //base case
        if(i >= row || j>= col) {
            return 0;
        }

        //explore all 3 directions
        int right = solve(matrix, i, j+1, row, col, maxi);
        int diagnol = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        //check can we build sqaure form current position
        if(matrix[i][j] == '1') {
            int ans = 1 + min(right, min(down, diagnol));
            //cout << "For i: " << i << "j: " << j << endl;
            //ye important hai 
            maxi = max(maxi, ans);
            return ans;

        }
        else {
            //agar 0 pr hi khade ho toh answer bhi zero hga
            return 0;
        }
     }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0; 
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        int ans = solve(matrix, i, j, row, col, maxi) ;
        return maxi*maxi;
    }
};