class Solution
{
public:
    int nodecount(struct Node *root)
    {
        if (!root)
            return 0;
        int l = nodecount(root->left);
        int r = nodecount(root->right);
        return 1 + l + r;
    }
    bool isCBT(struct Node *root, int i, int &n)
    {
        if (!root)
            return true;
        if (i >= n)
            return false;
        return isCBT(root->left, 2 * i + 1, n) && isCBT(root->right, 2 * i + 2, n);
    }
    bool isMaxHeap(struct Node *root)
    {
        if (!root)
            return true;

        bool l = isMaxHeap(root->left);
        bool r = isMaxHeap(root->right);

        int ans = false;
        if (!root->left && !root->right)
            ans = true;
        else if (root->left && !root->right)
            ans = root->data > root->left->data;
        else if (!root->left && root->right)
            ans = root->data > root->right->data;
        else
            ans = root->data > root->left->data && root->data > root->right->data;
        return ans && l && r;
    }
    bool isHeap(struct Node *tree)
    {
        int n = nodecount(tree);
        int i = 0;
        return isCBT(tree, i, n) && isMaxHeap(tree);
    }
};