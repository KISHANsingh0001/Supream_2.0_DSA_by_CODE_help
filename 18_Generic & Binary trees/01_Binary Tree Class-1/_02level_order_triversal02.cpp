// Implimentation of the binary tree and level order triversal........
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data; // Data members
    Node *left;
    Node *right;

    Node(int val)
    { // paramitrized CTOR
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createTree()
{
    int data;
    cout << "Enter the Value: " << endl;
    cin >> data;

    // Base case
    if (data == -1)
    {
        return NULL;
    }
    // step1 : Create a node
    Node *root = new Node(data);

    // step2 : create left subTree
    root->left = createTree();

    // step3 : create right subTree
    root->right = createTree();

    return root;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // asli traversal start krete h

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // valid node wala case
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);
    return 0;
}