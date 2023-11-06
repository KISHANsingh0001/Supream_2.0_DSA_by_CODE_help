//Reverse a linked list

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
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        //base case
        if(curr == NULL) {
            return prev;
        }
        //1 case hum solve krenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //baaaki kon sambhalega - recursion
        return reverseUsingRecursion(prev, curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseUsingRecursion(prev,curr);

        // while(curr != NULL) {
        //     ListNode* nextNode = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        // }
        // return prev;
    }
};


///Middle of a linked list
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
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            fast = fast ->next;
            if(fast != NULL) {
                fast = fast -> next;
                //main yaha keh skta hu k fast ne 2 step chal liye h 
                //ab slow ko bhi chalwao ek step
                slow = slow -> next;
            }
        }

        return slow;


        // int n = getLength(head);
        // int position = n/2 + 1;
        
        // ListNode* temp = head;
        // while(position != 1) {
        //     position--;
        //     temp = temp -> next;
        // }
        // return temp;
    }
};


///Palindrome Check Linked List
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
ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        //base case
        if(curr == NULL) {
            return prev;
        }
        //1 case hum solve krenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //baaaki kon sambhalega - recursion
        return reverseUsingRecursion(prev, curr);
    }
ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL) {
            fast = fast ->next;
            if(fast->next != NULL) {
                fast = fast -> next;
                slow = slow -> next;
            }
        }

        return slow;
    }
    bool compareList(ListNode* head1, ListNode* head2) {
        while( head2 != NULL) {
            if(head1 -> val != head2->val) {
                return false;
            }
            else {
                head1 = head1->next;
                head2=head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        //break into 2 havles
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode -> next;
        midNode->next = NULL;
        //reverse second half

        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);
        
        //compare both linked list
        bool ans = compareList(head, head2);
        return ans;
        
    }
};

///Cycle Check in Linked List
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

        map<ListNode*, bool> table;

        ListNode* temp = head;
        while(temp != NULL) {
            if(table[temp] == false) {
                table[temp] = true;
            }
            else{
                //cycle present
                return true;
            }
            temp = temp -> next;
        }
        //loop not present
        return false;
        
    }
};
