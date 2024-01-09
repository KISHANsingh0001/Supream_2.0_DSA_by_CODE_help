#include <iostream>
using namespace std;
// tabulation method
int solveUsingTabulation(int n)
{
    // step1: create dp array
    vector<int> dp(n + 1, -1);
    // step2: analyse base case and fill dp array
    dp[0] = 0;
    if (n == 0)
    {
        return 0;
    }
    dp[1] = 1;
    // step3: fill the remaingin dp array
    // array size = n+1
    // index move from 0 to n
    // 0 and 1 index ko already fill krlia h
    // 2 index se n index tak abhi filled nahi h
    for (int index = 2; index <= n; index++)
    {
        // copy paste karo recursive logic ko
        // repalce recursive calls  with dp array
        // make sure dp array is using looping variable
        dp[index] = dp[index - 1] + dp[index - 2];
    }
    // return ans;
    return dp[n];
}
int main()
{
    int n = 6;
    cout << n << "'th fibonacci number is: " << solveUsingTabulation(n);
    return 0;
}