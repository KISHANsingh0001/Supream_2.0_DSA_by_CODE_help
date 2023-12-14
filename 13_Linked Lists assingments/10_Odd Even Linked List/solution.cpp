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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next == NULL) return head;

        ListNode* oddit = head; // oddit means odd index itrator
        ListNode* evenit = head->next; //evenit means even index itrator
        ListNode* evenHead = evenit;
        while(evenit && evenit->next){
            oddit->next = evenit->next;
            evenit->next = evenit->next->next;
            oddit = oddit->next;
            evenit = evenit->next;
        }
        oddit->next = evenHead;
        return head;
    }
};