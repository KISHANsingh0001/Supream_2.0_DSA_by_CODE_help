/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL) {
            return NULL;
        }

        //case 1: p and q both comes in left subtree ofroot node
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p,q);
            return leftAns;
        }
        //case 2: p and q both comes in right subtree of root node
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        //case 3;
        //p is in left subtree of root node && q is on right subtree of root node
        // if(p->val < root->val && q->val > root->val) {
        //     return root;
        // }
        //  //case 4;
        // //q is in left subtree of root node && p is on right subtree of root node
        // if(q->val < root->val && p->val > root->val) {
        //     return root;
        // }
        return root;
    }
};