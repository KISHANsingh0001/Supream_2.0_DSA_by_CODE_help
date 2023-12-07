// Implimentation of the binary tree  from my self ... 
#include<iostream>
using namespace std;
class Node{
   public:
      int data;  // Data members
      Node* left;
      Node* right;

      Node(int val){ // paramitrized CTOR
        this->data = val;
        this->left = NULL;
        this->right = NULL;
      }
};
Node* createTree(){
    int data;
    cout<<"Enter the Value: "<<endl;
    cin>>data;

    // Base case
    if(data == -1){
        return NULL;
    }
    // step1 : Create a node
    Node* root = new Node(data);
    
    // step2 : create left subTree
    root->left = createTree();

    // step3 : create right subTree
    root->right = createTree();

    return root;
}

void printPreorder(Node* root){ // Pri Order Trivarsal (NLR)
    // Base case 
    if(root == NULL){
        return;
    }
    //N
    cout<<root->data<<" ";
    //L
    printPreorder(root->left);
    //R
    printPreorder(root->right);
}

void printInorder(Node* root){ // Pri Order Trivarsal (NLR)
    // Base case 
    if(root == NULL){
        return;
    }
    //L
    printInorder(root->left);
    //N
    cout<<root->data<<" ";
    //R
    printInorder(root->right);
}

void printPostorder(Node* root){ // Post Order Trivarsal (LRN)
    // Base case 
    if(root == NULL){
        return;
    }
    //L
    printInorder(root->left);
    //R
    printInorder(root->right);
    //N
    cout<<root->data<<" ";
}

int main()
{
    Node* root = createTree();
    printPreorder(root);
    return 0;
}