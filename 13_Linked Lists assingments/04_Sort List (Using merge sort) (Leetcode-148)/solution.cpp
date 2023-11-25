// Leetcode problem number 148 sort Lists
class Solution {
public:
    ListNode* findMid(ListNode* head){
     ListNode* slow = head;
     ListNode* fast = head->next;
     while(fast &&  fast->next){
             fast = fast->next->next;
             slow = slow->next;
         }
         return slow;
     }
    
     ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;
        while(left && right){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }
        if(left){
            mptr->next = left;
        }
        if(right){
            mptr->next = right;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
     // base casese
     if(head == 0 || head->next == 0){
         return head;
     }

     // find the mid node 
     ListNode* midNode = findMid(head);
     ListNode* left = head;
     ListNode* right = midNode->next;
     midNode->next = 0; // break the links 

     // recursive calls for sort the list
      left = sortList(left);
      right = sortList(right);
    // Merge both halfs using merge function
    ListNode* mergedLL = mergeTwoLists(left , right);

    return mergedLL;

    }
};