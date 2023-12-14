//                     LeetCode-2816. Double a Number Represented as a Linked List
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
    void solveDouble(ListNode *&head , int &carry){
        if(head == NULL) return;
        solveDouble(head->next , carry);
        int pro = head->val * 2 + carry;
        head->val = pro % 10;
        carry = pro/10;
    }
    ListNode* doubleIt(ListNode* &head) {
        int carry = 0;
        solveDouble(head , carry);
        if(carry != 0){
            ListNode * carryNode = new ListNode(carry);
            carryNode->next = head;
            head = carryNode;
        }
        return head;
    }
};    
