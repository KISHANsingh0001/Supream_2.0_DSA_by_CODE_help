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
    bool isCompleteTree(TreeNode* root) {
      queue<TreeNode*>q;
      q.push(root);
      bool nullFound = false;
      while(!q.empty()){
          TreeNode* front = q.front();
          q.pop();
          if(front == NULL){
              nullFound = true;
          }
          else{
              if(nullFound == true){
                  return false;
              }
              q.push(front->left);
              q.push(front->right);
          }
      }
      return nullFound;  
    }
};