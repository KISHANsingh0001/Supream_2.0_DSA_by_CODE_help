#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solveRE(vector<int> &nums1, vector<int> &nums2, int i, int p1, int p2)
{
    // Base case
    if (i == nums1.size())
        return 0;

    int swap = INT_MAX, noSwap = INT_MAX;
    // Swap karke dekho
    if (p1 < nums2[i] && p2 < nums1[i])
    {
        swap = 1 + solveRE(nums1, nums2, i + 1, nums2[i], nums1[i]);
    }
    // swap nahi karke dekho
    if (p1 < nums1[i] && p2 < nums2[i])
    {
        noSwap = solveRE(nums1, nums2, i + 1, nums1[i], nums2[i]);
    }

    return min(swap, noSwap);
}
int solveTD(vector<int> &nums1, vector<int> &nums2, int i, int p1, int p2,
            vector<vector<int>> &dp, int isSwap)
{
    // Base case
    if (i == nums1.size())
        return 0;

    if (dp[i][isSwap] != -1)
        return dp[i][isSwap];

    int swap = INT_MAX, noSwap = INT_MAX;
    // Swap karke dekho
    if (p1 < nums2[i] && p2 < nums1[i])
    {
        swap = 1 + solveTD(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
    }
    // swap nahi karke dekho
    if (p1 < nums1[i] && p2 < nums2[i])
    {
        noSwap = solveTD(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
    }

    return dp[i][isSwap] = min(swap, noSwap);
}
int solveBU(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

    for (int i = nums1.size() - 1; i >= 1; i--)
    {
        for (int j = 1; j >= 0; --j)
        {
            int p1 = nums1[i - 1];
            int p2 = nums2[i - 1];
            if (j)
            {
                swap(p1, p2);
            }
            int swap = INT_MAX, noSwap = INT_MAX;
            // Swap karke dekho
            if (p1 < nums2[i] && p2 < nums1[i])
            {
                swap = 1 + dp[i + 1][1];
            }
            // swap nahi karke dekho
            if (p1 < nums1[i] && p2 < nums2[i])
            {
                noSwap = dp[i + 1][0];
            }
            dp[i][j] = min(swap, noSwap);
        }
    }
    return dp[1][0];
}

int main()
{
    vector<int>nums1 = {1,3,5,4};
    vector<int>nums2 = {1,2,3,7};
    // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
    // cout<<"Maximum operation needed is : "<<solveRE(nums1 , nums2 , 0 , -1 , -1);
    // cout<<"Maximum operation needed is : "<<solveTD(nums1, nums2, 0, -1, -1, dp, 0);
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    cout<<"Maximum operation needed is : "<<solveBU(nums1, nums2)<<endl;
    return 0;
}