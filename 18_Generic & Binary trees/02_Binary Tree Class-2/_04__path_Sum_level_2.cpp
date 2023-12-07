//                          LEETCODE - 113 (_path_Sum_level_2)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum) {
        //base case
        if(root == NULL) {
            return;
        }
        //1 casE SOLVE KRNA H 
        sum += root->val;
        temp.push_back(root->val);

        //extra case
        if(root->left == NULL && root->right == NULL) {
            //verify
            if(sum == targetSum) {
                //store temp path in final ans array
                ans.push_back(temp);
            }
            else {
                return;
            }
        }

        //baaki recursion sambhal lega
        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};