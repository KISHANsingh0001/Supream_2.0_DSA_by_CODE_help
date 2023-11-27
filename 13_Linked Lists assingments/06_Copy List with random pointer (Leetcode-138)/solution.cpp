https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head == NULL) return 0;
       //step1: Clone the orignal node to new node
       Node* it = head; //itrate over orignal linked list
       while(it != NULL){
        Node* clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
       }

       //step2: assinging the random pointer on the new node with the help of orignal node
       it = head;
       while(it){
           Node* clonedNode = it->next;
           clonedNode->random = it->random != NULL ? it->random->next : nullptr;
           it = it->next->next;
       }
       //step3: Detach the orignal node and new node to each other
       it = head;
       Node* clonedHead = it->next;
       while(it){
           Node* clonedNode = it->next;
           it->next = it->next->next;
           if(clonedNode->next){
               clonedNode->next = clonedNode->next->next;
           }
           it = it->next;
       }
       return clonedHead;
    }
};