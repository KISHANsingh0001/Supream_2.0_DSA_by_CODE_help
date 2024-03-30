/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int solveUsingRec(TreeNode *root)
    {
        if (!root)
            return 0;

        int include = 0, exclude = 0;
        // if i rob the current house node
        include = root->val;
        if (root->left)
        {
            include += solveUsingRec(root->left->left) +
                       solveUsingRec(root->left->right);
        }
        if (root->right)
        {
            include += solveUsingRec(root->right->right) +
                       solveUsingRec(root->right->left);
        }
        // if i do not rob the current house
        exclude = solveUsingRec(root->left) + solveUsingRec(root->right);

        return max(include, exclude);
    }
    int solveUsingMem(TreeNode *root, unordered_map<TreeNode *, int> &dp)
    {
        if (!root)
            return 0;
        if (dp.find(root) != dp.end())
        {
            return dp[root];
        }
        int include = 0, exclude = 0;
        // if i rob the current house node
        include = root->val;
        if (root->left)
        {
            include += solveUsingMem(root->left->left, dp) +
                       solveUsingMem(root->left->right, dp);
        }
        if (root->right)
        {
            include += solveUsingMem(root->right->right, dp) +
                       solveUsingMem(root->right->left, dp);
        }
        // if i do not rob the current house
        exclude =
            solveUsingMem(root->left, dp) + solveUsingMem(root->right, dp);

        return dp[root] = max(include, exclude);
    }
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> dp;
        return solveUsingMem(root, dp);
    }
};