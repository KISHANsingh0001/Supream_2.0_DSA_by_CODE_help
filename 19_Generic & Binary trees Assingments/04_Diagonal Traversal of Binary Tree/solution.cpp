// Input :      root
//             8
//          /     \
//         3      10
//       /   \      \
//      1     6     14
//          /   \   /
//         4     7 13
// Output : 8 10 14 3 6 7 13 1 4

vector<int> diagonal(Node *root)
{
    if (!root)
        return {0};
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp != NULL)
        {
            ans.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
    
}
