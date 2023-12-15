//                              Leetcode 110. Balanced Binary Tree
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
    int height(TreeNode* &root , bool &isBalanced){
        //Base case
        if(root == NULL)
         return 0;

        int leftH = height(root->left,isBalanced);
        int rightH = height(root->right,isBalanced);

        if(isBalanced && abs(leftH - rightH)>1){
             isBalanced = false;
        }
        return max(leftH , rightH)+1;
      
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
       height(root , isBalanced);
       return isBalanced;
    }
};