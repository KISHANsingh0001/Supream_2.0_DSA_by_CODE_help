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
    map<pair<int, int>, vector<TreeNode *>> mp;
    // Method 1 Solve Using Simple Recurssion
    vector<TreeNode *> solveUsingRec(int start, int end)
    {
        // Base case
        if (start > end)
            return {NULL};
        if (start == end)
        {
            TreeNode *root = new TreeNode(start);
            return {root};
        }
        // har ek element ko root banker dekhna hai
        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {

            vector<TreeNode *> left_bst = solveUsingRec(start, i - 1);
            vector<TreeNode *> right_bst = solveUsingRec(i + 1, end);

            // make every possible pairs of bst's
            for (auto left_part : left_bst)
            {
                for (auto right_part : right_bst)
                {
                    // firstly make a root node
                    TreeNode *root = new TreeNode(i);
                    root->left = left_part;
                    root->right = right_part;
                    // ans main push karna hai tree ki root node ko
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    // Method 2 Solve Using Recurssion + Memoization (Top Down dp)
    vector<TreeNode *> solveUsingMem(int start, int end)
    {
        // Base case
        if (start > end)
            return {NULL};
        if (start == end)
        {
            TreeNode *root = new TreeNode(start);
            return {root};
        }
        if (mp.find({start, end}) != mp.end())
        {
            return mp[{start, end}];
        }
        // har ek element ko root banker dekhna hai
        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {

            vector<TreeNode *> left_bst = solveUsingMem(start, i - 1);
            vector<TreeNode *> right_bst = solveUsingMem(i + 1, end);

            // make every possible pairs of bst's
            for (auto left_part : left_bst)
            {
                for (auto right_part : right_bst)
                {
                    // firstly make a root node
                    TreeNode *root = new TreeNode(i);
                    root->left = left_part;
                    root->right = right_part;
                    // ans main push karna hai tree ki root node ko
                    ans.push_back(root);
                }
            }
        }
        mp[{start, end}] = ans;
        return mp[{start, end}];
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solveUsingRec(1, n);
    }
};