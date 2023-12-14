//                          LeetCode-2181. Merge Nodes in Between Zeros
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       if(head == NULL) return NULL;

       int sum = 0;
       ListNode* slow = head;
       ListNode* fast = head->next;
       ListNode* lastNode = NULL;
       while(fast){
           sum += fast->val;
           if(fast->val == 0){
            slow->val = sum;
            lastNode = slow;
            slow = slow->next;
            sum = 0;
           }
           fast = fast->next;
       }
       ListNode* temp = slow;

       lastNode->next = NULL;
       while(temp){
           ListNode * nxt = temp->next;
           delete temp;
           temp = nxt;
       }
     
       return head;
    }
};