 // GFG problem solution................
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(head == NULL) return;
        Node* it = head; 
        for(int i = 0 ; i<M-1 ; i++){
            if(it==NULL) return;
            it = it->next;
        }
        if(it == NULL){
            return;
        }
        Node* mthNode = it;
        it = mthNode->next;
        for(int i = 0 ; i<N ; i++){
            if(it == NULL) break;
            
            Node* temp = it->next;
            delete it;
            it = temp;
        }
        mthNode->next = it;
        linkdelete(it , M , N);
    }
};