// Leet code problem number 643. Maximum Average Subarray I
// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
// Any answer with a calculation error less than 10-5 will be accepted.
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip> // for setprecision
using namespace std;

double sidlingWindowMethod(vector<int> &nums, int &k)
{
    int i = 0, j = k - 1;
    int sum = 0;
    for (int y = i; y <= j; y++)
    {
        sum += nums[y];
    }
    int maxSum = sum;
    j++;
    while (j < nums.size())
    {
        sum = sum - nums[i++];
        sum = sum + nums[j++];
        maxSum = max(maxSum, sum);
    }
    double maxAvg = maxSum / (double)k;
    return maxAvg;
}
double findMaxAverage(vector<int> &nums, int k)
{
    return sidlingWindowMethod(nums, k);
}
int main()
{
    int n, k;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the vector elements: " << endl;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    cout << "Enter the value of pairs: " << endl;
    cin >> k;
    double ans = findMaxAverage(nums, k);
    cout << "maximum average of " << k << " pairs is: " << fixed << setprecision(4) << ans << endl;
    return 0;
}