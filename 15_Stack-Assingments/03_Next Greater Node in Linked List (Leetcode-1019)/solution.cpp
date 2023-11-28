// https://leetcode.com/problems/next-greater-node-in-linked-list/description/

vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
    //step1-convert linked list into vector
       while(head){
           ll.push_back(head->val);
           head = head ->next;
       }
      stack<int>st;
      for(int i = 0 ; i<ll.size(); i++)
      {
          while(!st.empty() && ll[i] > ll[st.top()])
           {
              int k = st.top();
              st.pop();
              ll[k] = ll[i];
           }
          st.push(i);
      } 
      while(!st.empty()){
          ll[st.top()] = 0;
          st.pop();
      } 
      ll[ll.size()- 1] = 0; // last vala next greter always 0 hi hoga
      return ll;
    }