#include <iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n) {
	//base case
	if(index >=n) {
		return 0;
	}

	//inc / exc
	int include = 0;
	if(wt[index] <= capacity) {
		include = profit[index] + solveUsingRecursion(capacity-wt[index], wt, profit, index+1, n);
	}
	int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index+1, n);
	int ans = max(include, exclude);
	return ans;
}
void printdparray(vector<vector<int> >& dp) {
	cout << endl << endl << "printing dp array" << endl;
	for(int i=0; i<dp.size(); i++) {
		for(int j=0; j<dp[0].size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int> >& dp) {
	//base case
	if(index >=n) {
		return 0;
	}

	//already exists
	if(dp[capacity][index] != -1){
		return dp[capacity][index];
	}

	//inc / exc
	int include = 0;
	if(wt[index] <= capacity) {
		include = profit[index] + solveUsingMem(capacity-wt[index], wt, profit, index+1, n, dp);
	}
	int exclude = 0 + solveUsingMem(capacity, wt, profit, index+1, n, dp);
	dp[capacity][index] = max(include, exclude);
	return dp[capacity][index];
}


int solveUsingTabulation(int capacity, int wt[], int profit[], int n) {
	vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));

	for(int row = 0; row<=capacity; row++) {
		dp[row][n] = 0;
	}

	for(int i=0; i<=capacity; i++) {
		for(int j=n-1; j>=0; j--) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + dp[i-wt[j]][j+1];
			}
			int exclude = 0 + dp[i][j+1];
			dp[i][j] = max(include, exclude);
		}
	}

	//printdparray(dp);
	return dp[capacity][0];
	
}

int solveUsingTabulationSO(int capacity, int wt[], int profit[], int n) {
	vector<int> next(capacity+1, 0);
	vector<int> curr(capacity+1, -1);


	for(int j=n-1; j>=0; j--) {
		for(int i=0; i<=capacity; i++) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + next[i-wt[j]];
			}
			int exclude = 0 + next[i];
			curr[i] = max(include, exclude);
		}
		//shifting
		next = curr;
	}
	return curr[capacity];
}


int solveUsingTabulationSO2(int capacity, int wt[], int profit[], int n) {
	vector<int> next(capacity+1, 0);
	
	for(int j=n-1; j>=0; j--) {
		for(int i=capacity; i>=0; i--) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + next[i-wt[j]];
			}
			int exclude = 0 + next[i];
			next[i] = max(include, exclude);
		}
		//shifting
		// next = curr;
	}
	return next[capacity];
}



int main() {

	int capacity = 6;
	int wt[] = {1,2,3};
	int profit[] = {10,15,40};
//int index = 0;
	int n = 3;

	vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));

	int ans = solveUsingTabulationSO2(capacity,wt, profit, n);
	cout << "max Profit: " << ans << endl;


	return 0;
}

// int solveUsingRecursion(int n, int k) {
// 	//base case
// 	if(n == 1) {
// 		return k ;
// 	}
// 	if(n ==2) {
// 		return (k + k*(k-1));
// 	}
// 	int ans = (solveUsingRecursion(n-1,k) + solveUsingRecursion(n-2,k))*(k-1);
// 	return ans;
// }

// int solveUsingMem(int n, int k, vector<int>& dp) {
// 	//base case
// 	if(n == 1) {
// 		return k ;
// 	}
// 	if(n ==2) {
// 		return (k + k*(k-1));
// 	}
// 	//already exists
// 	if(dp[n] != -1) {
// 		return dp[n];
// 	}
// 	dp[n] = (solveUsingMem(n-1,k, dp) + solveUsingMem(n-2,k,dp))*(k-1);
// 	return dp[n];
// }

// int solveUsingTabulation(int n, int k) {
// 	vector<int> dp(n+1, -1);
// 	dp[1] = k;
// 	dp[2] = k + k*(k-1);
// 	for(int i=3; i<=n; i++) {
// 		dp[i] = (dp[i-1] + dp[i-2])*(k-1);
// 	}
// 	return dp[n];
// } 


// int solveUsingTabulationSO(int n, int k) {
// 	// vector<int> dp(n+1, -1);
// 	int prev2 = k;
// 	int prev1 = k + k*(k-1);
// 	if(n==1) {
// 		return prev2;
// 	}
// 	if(n==2) {
// 		return prev1;
// 	}
// 	int curr;
// 	for(int i=3; i<=n; i++) {
// 		curr = (prev1 + prev2)*(k-1);
// 		//shift
// 		prev2 = prev1;
// 		prev1 = curr;
// 	}
// 	return curr;
// } 


// int main() {
//   	int n = 3;
// 	int k = 2;

// 	//vector<int> dp(n+1, -1);
// 	int ans = solveUsingTabulation(n,k);
// 	cout << "Ans: " << ans << endl;

	


// 	return 0;
// }