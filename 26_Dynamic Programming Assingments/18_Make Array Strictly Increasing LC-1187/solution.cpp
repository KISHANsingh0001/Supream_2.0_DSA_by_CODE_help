class Solution
{
public:
#define INF (1e9 + 1)
    map<pair<int, int>, int> dp;
    int solveUsingRec(vector<int> &arr1, vector<int> &arr2, int prev, int i)
    {
        // Base case
        if (i == arr1.size())
        {
            return 0;
        }
        int op1 = INF;
        if (prev < arr1[i])
        {
            // no operation
            op1 = solveUsingRec(arr1, arr2, arr1[i], i + 1);
        }
        int op2 = INF;
        auto it = upper_bound(begin(arr2), end(arr2), prev);
        if (it != arr2.end())
        {
            int index = it - arr2.begin();
            // arr1[i] = arr2[index]; this will modify our orignal array
            op2 = 1 + solveUsingRec(arr1, arr2, arr2[index], i + 1);
        }
        return min(op1, op2);
    }
    int solveUsingMem(vector<int> &arr1, vector<int> &arr2, int prev, int i)
    {
        // Base case
        if (i == arr1.size())
        {
            return 0;
        }
        if (dp.find({prev, i}) != dp.end())
        {
            return dp[{prev, i}];
        }
        int op1 = INF;
        if (prev < arr1[i])
        {
            // no operation
            op1 = solveUsingMem(arr1, arr2, arr1[i], i + 1);
        }
        int op2 = INF;
        auto it = upper_bound(begin(arr2), end(arr2), prev);
        if (it != arr2.end())
        {
            int index = it - arr2.begin();
            // arr1[i] = arr2[index]; this will modify our orignal array
            op2 = 1 + solveUsingMem(arr1, arr2, arr2[index], i + 1);
        }
        return dp[{prev, i}] = min(op1, op2);
    }
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {

        sort(begin(arr2), end(arr2));
        int ans = solveUsingMem(arr1, arr2, -1, 0);
        return ans == INF ? -1 : ans;
    }
};