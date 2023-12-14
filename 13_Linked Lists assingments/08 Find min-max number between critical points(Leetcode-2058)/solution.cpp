//LeetCode-2058. Find the Minimum and Maximum Number of Nodes Between Critical Points.
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1 , -1};
        ListNode* prev = head;
        if(prev == NULL) return ans;

        ListNode* curr = head->next;
        if(curr == NULL) return ans;

        ListNode* nxt = head->next->next;
        if(nxt == NULL) return ans;

        int firstCp = -1;
        int lastCp = -1;
        int mindis = INT_MAX;
        int i = 1;
        while(nxt){
            bool isCp = ((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && 
            curr->val < nxt->val) ? true : false);

            if(isCp && firstCp == -1){
                firstCp = i;
                lastCp = i;
            }
            else if(isCp && firstCp != -1){
                mindis = min(mindis , i - lastCp);
                lastCp = i;
            }
            ++i;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        if(lastCp == firstCp){
            return ans;
        }
        else{
            ans[0] = mindis;
            ans[1] = lastCp - firstCp;
        }
        return ans;
    }
};