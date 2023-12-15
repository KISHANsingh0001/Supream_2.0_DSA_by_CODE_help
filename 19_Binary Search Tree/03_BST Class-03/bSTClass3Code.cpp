#include <iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insertIntoBST(Node* root, int data) {
	if(root == NULL) {
		root = new Node(data);
		return root;
	}

	//its not the first node
	if(data > root->data) {
		root->right = insertIntoBST( root->right, data);
	}
	else {
		root->left = insertIntoBST( root->left, data);
	}
	return root;
}

void createBST(Node* &root) {
	cout << "Enter data:" << endl;
	int data;
	cin >> data;

	while(data != -1) {
		root = insertIntoBST(root, data);
		cout << "Enter data:" << endl;
		cin >> data;
	}
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}

//convert this BST into a sorted Doubly Linked lIst
void convertBSTtoDLL(Node* root, Node* &head) {
	if(root == NULL ) {
		return;
	}

	//RNL

	//R 
	convertBSTtoDLL(root->right, head);

	//N
	//attaching next pointer of current node to heda of LL
	root->right = head;
	//attaching prev pointer of head of LL to current node
	if(head != NULL)
		head ->left = root;
	//head update
	head = root;

	//L
	
	convertBSTtoDLL(root->left, head);
}

Node* convertDLLtoBST(Node* &head, int n) {
	//base case
	if(head == NULL || n<=0) {
		return NULL;
	}

	//LNR
	//L
	Node* leftSubtree = convertDLLtoBST(head, n/2);

	//N 
	Node* root = head;
	root->left = leftSubtree;
	//head update
	head  = head ->right;

	///R
	Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
	root->right = rightSubtree;
	return root;
	
}

void printLinkedList(Node* head) {
	Node* temp = head;
	cout << "printing the entire list: " << endl;
	while(temp != NULL) {
		cout << temp->data <<"->";
		temp = temp->right;
	}
	cout << endl;
}

int main() {

	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);

	first->right = second;
	second->left = first;
	second->right = third;
	third->left = second;

	Node* head = first;
	//10<->20<->30

	Node* root = convertDLLtoBST(head, 3);
	levelOrderTraversal(root);
	
	
	// int inorder[] = {10,20,30,40,50,60,70};
	// int size = 7;
	// int start = 0;
	// int end = size-1;
	// Node* root = bstFromInorder(inorder, start, end);

	// levelOrderTraversal(root);
	// Node* head = NULL;
	// convertBSTtoDLL(root, head);
	// printLinkedList(head);

	// Node* root = NULL;
	// createBST(root);

	// levelOrderTraversal(root);

	// cout << endl << "Inorder: " ;
	// inorder(root);
	// cout << endl << "Preorder: ";
	// preorder(root);
	// cout << endl << "PostOrder: ";
	// postorder(root);


	// cout << endl;
	// Node* minNode = minValue(root);
	// if(minNode == NULL) {
	// 	cout << "There is no node in tree, so no min value" << endl;
	// }
	// else {
	// 	cout << "Min Value: " << minNode->data << endl;
	// }

	// cout << endl;
	// Node* maxNode = maxValue(root);
	// if(maxNode == NULL) {
	// 	cout << "There is no node in tree, so no max value" << endl;
	// }
	// else {
	// 	cout << "Max Value: " << maxNode->data << endl;
	// }

	// int target ;
	// cout << "Enter the value of target: " << endl;
	// cin >> target;

	// while(target != -1) {
	// 	root = deleteFromBST(root,  target);
	// 	cout << endl << "Printing Level Order Traversal: " << endl;
	// 	levelOrderTraversal(root);

	// 	cout << "Enter the value of target: " << endl;
	// 	cin >> target;

	// }

	// int t;
	// cout << "Enter the target: " << endl;
	// cin >> t;

	// while(t != -1) {
	// 	bool ans = searchInBST(root, t);
	// 	if(ans == true) {
	// 		cout << "Found" << endl;
	// 	}
	// 	else {
	// 		cout << "Not Found" << endl;
	// 	}

	// 	cout << "Enter the target: " << endl;
	// 	cin >> t;

	// } 



	return 0;
}
