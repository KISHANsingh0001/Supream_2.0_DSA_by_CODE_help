#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

void modifyQueue(queue<int>& q, int k, vector<int>& ans) {
    int size = q.size();
    int n = q.size();
    stack<int> stk;

    // step 1 - push k elements in the queue
    for (int i = 0; i < k; i++) {
        int frontEle = q.front();
        q.pop();
        stk.push(frontEle);
    }

    // step 2: push k elements from stack to queue
    while (!stk.empty()) {
        int topEle = stk.top();
        stk.pop();
        q.push(topEle);
    }

    // step 3 - pop and push (N-k) elements from queue to same queue
    for (int i = 0; i < (n - k); i++) {
        int frontEle = q.front();
        q.pop();
        q.push(frontEle);
    }

    // Copy the modified queue elements to the ans vector
    for (int i = 0; i < size; i++) {
        ans[i] = q.front();
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    vector<int> ans(7);
    modifyQueue(q, 3, ans);

    // Print the modified queue elements
    for (auto i : ans) {
        cout << i << " ";
    }
    cout<<endl;

    return 0;
}
