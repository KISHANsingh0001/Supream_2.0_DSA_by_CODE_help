https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* a , Node*b){
    if(a == NULL) return b;
    if(b==NULL) return a;
    
    Node* ans = 0;
    if(a->data < b->data){
        ans = a;
        a->bottom = merge(a->bottom , b);
    }
    else{
        ans = b;
        b->bottom = merge(a , b->bottom);
    }
    return ans;
}
Node *flatten(Node *root)
{
    if(root == NULL) return 0;
    
    Node *mergell = merge(root , flatten(root->next));
    return mergell;
}