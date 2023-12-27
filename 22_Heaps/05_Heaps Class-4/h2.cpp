class Info{
    public:
        char val;
        int count;
    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare{
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};


class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        //count freq of all chartacter in string
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }
        //push all characters in maxHeap
        priority_queue<Info, vector<Info>, compare> maxHeap;
        //push all characters into heap, where freq > 0
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                Info temp(i+'a', freq[i]);
                // temp.val = i+'a';
                // temp.count = freq[i];
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }
        }

        //if 1 element bacha h, toh alag se handle karo
        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;

            if(first.count != 0 ) {
                //answer not possible
                return  "";
            }
        }
    return ans;
 
    }
};