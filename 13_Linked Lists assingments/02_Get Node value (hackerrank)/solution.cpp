//Given a pointer to the head of a linked list and a specific position, determine the data value at that position.
//Count backwards from the tail node. The tail is at postion 0, its parent is at 1 and so on.

//1) solution - using recursion
void fun(SinglyLinkedListNode* head, int& positionFromTail , int &ans){
    // Base case
    if(head ==NULL){
        return;
    }
    fun(head->next , positionFromTail , ans);
    if(positionFromTail == 0){
        ans = head->data;
    }
    positionFromTail--;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
       int ans = -1;
       fun( llist, positionFromTail , ans);
       return ans;
}

//2) solution - itrative approch
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
     SinglyLinkedListNode* temp = llist;
     int size = 0;
     while (temp!=NULL) {
       size++;
       temp = temp->next;
     }
     int position = size - positionFromTail;
     temp = llist;
     while(position != 1){
         position--;
         temp = temp->next;
     }
     return temp->data;
}