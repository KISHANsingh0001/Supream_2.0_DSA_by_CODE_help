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
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, compare> maxHeap;
        if(a > 0) {
            Info temp('a', a);
            maxHeap.push(temp);
        }
        if(b > 0) {
            Info temp('b', b);
            maxHeap.push(temp);
        }
        if(c > 0) {
            Info temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";
        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();
            
            if(first.count >=2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else {
                ans.push_back(first.val);
                first.count--;
            } 

            if(second.count >=2 && second.count >= first.count) {
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.count -= 2;
            }
            else {
                ans.push_back(second.val);
                second.count--;
            } 

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }       
        }

        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            if(first.count >=2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.count -= 2;
            }
            else {
                ans.push_back(first.val);
                first.count--;
            } 
        } 
        return ans;
    }
};