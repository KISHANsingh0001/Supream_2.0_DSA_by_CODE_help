#include <iostream>
#include<queue>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}


};

//it returns root node of the created tree
Node* createTree() {
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

  if(data == -1) {
	return NULL;
  }
  //Step1: create Node
  Node* root = new Node(data);
  //Step2: Create left subtree
  //cout << "left of Node: " << root->data << endl;
  root->left = createTree();
  //Step3: Craete right subtree
  //cout << "right of Node: " << root->data << endl;
  root->right = createTree();
  return root;

}

void preOrderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return;
	}
	// N L R
	//N 
	cout << root->data << " ";
	// L
	preOrderTraversal(root->left);
	// R
	preOrderTraversal(root->right);
}

void inorderTraversal(Node* root) {
	//LNR
	//base case
	if(root == NULL) {
		return;
	}
	//L
	inorderTraversal(root->left);
	// N
	cout << root->data << " ";
	// R
	inorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	//base case
	if(root == NULL) {
		return;
	}
	//L
	postOrderTraversal(root->left);
	//R
	postOrderTraversal(root->right);
	//N
	cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

int maxDepth(TreeNode* root) {

// IMP Galti
if(root==NULL)
	return 0;

queue<TreeNode*> q;
q.push(root);
q.push(NULL);
int count = 1;

//asli traversal start krete h 

while(!q.empty()) {
	TreeNode* front = q.front();
	q.pop();

	if(front == NULL) {
		cout << endl;
		if(!q.empty()) {
			count++;
			q.push(NULL);
		}
	}
	else {
		//valid node wala case
		//cout << front->data << " ";

		if(front->left != NULL) {
			q.push(front->left);
		}
		if(front->right != NULL) {
			q.push(front->right);
		}
	}
}
return count;


	// //base case
	// if(root == NULL ) {
	//     return 0;
	// }

	// int leftHeight = maxDepth(root->left);
	// int rightHeight = maxDepth(root->right);
	// int height = max(leftHeight, rightHeight) + 1;
	// return height;

}

int height(TreeNode* root) {
	//base case
	if(root == NULL ) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	int height = max(leftHeight, rightHeight) + 1;
	return height;
}

int diameterOfBinaryTree(TreeNode* root) {
	//base case
	if(root == NULL) {
		return 0;
	}   
	int option1 = diameterOfBinaryTree(root->left);
	int option2 = diameterOfBinaryTree(root->right);
	int option3 = height(root->left) + height(root->right);
	int diameter = max(option1, max(option2, option3));
	return diameter;
}


int main() {

	  Node* root = createTree();
	  //cout << root->data << endl;
	  cout << "Printing Preorder: ";
	  preOrderTraversal(root);
	  cout << endl;

	  cout << "Printing Inorder: ";
	  inorderTraversal(root);
	  cout << endl;

	  cout << "Printing PostOrder: ";
	  postOrderTraversal(root);
	  cout << endl;

	  cout << "Level Order : ";
	  levelOrderTraversal(root);
	  cout << endl;

  return 0;
}