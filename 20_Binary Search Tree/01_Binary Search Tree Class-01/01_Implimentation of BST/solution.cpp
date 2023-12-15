#include <iostream>
#include <queue>
using namespace std;
class Node
{
public: // Data members
    int data;
    Node *left;
    Node *right;

    // paramitized ctor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }

    // 1 case hum solve karege
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node *&root)
{
    int data;
    cout << "Enter the value : " << endl;
    cin >> data;50
    

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter the value : " << endl;
        cin >> data;
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
}
int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    return 0;
}