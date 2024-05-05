class Solution
{
public:
    void solveUsingBS(vector<int> &nums, vector<int> &lis)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        lis.push_back(1);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
                lis.push_back(ans.size());
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
                lis.push_back(index + 1);
            }
        }
    }
    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> lis, lds;
        solveUsingBS(nums, lis);
        // reverse(nums.begin() , nums.end());
        reverse(begin(nums), end(nums));
        solveUsingBS(nums, lds);
        int largestMountain = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)
                continue;
            largestMountain = max(largestMountain, lis[i] + lds[nums.size() - i - 1] - 1);
        }

        return nums.size() - largestMountain;
    }
};