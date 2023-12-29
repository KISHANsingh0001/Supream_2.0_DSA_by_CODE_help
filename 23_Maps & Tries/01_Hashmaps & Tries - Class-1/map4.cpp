/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode* ,bool> mapping;
        ListNode* temp = head;

        while(temp != NULL) {
            //address check
            if(mapping.find(temp) != mapping.end()) {
                //cycle present
                return true;
            }
            else {
               // node not visited beforehand
               //store
               mapping[temp] = true;
            }
            temp = temp ->next;
        }
        //cycle absenet
        return false;
        
    }
};