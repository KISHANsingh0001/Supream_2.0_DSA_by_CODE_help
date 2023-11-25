#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> rearrangeQueue(queue<int> &first){
        int size = first.size();
        queue<int> second;
        vector<int>ans(size);
        
        for(int i = 0 ; i<size/2 ; i++){
            int temp = first.front();
            first.pop();
            second.push(temp);
        }
        
        for(int i = 0 ; i<size/2 ; i++){
            int temp = second.front();
            second.pop();
            first.push(temp);
            
            int temp1 = first.front();
            first.pop();
            first.push(temp1);
        }
        for(int i = 0 ; i<size ; i++){
            ans[i] = first.front();
            first.pop();
        }
        return ans;
    }
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    vector<int> ans = rearrangeQueue(q);
    // cout<<"befor interleave the elements: "<<endl;
    //  while (!q.empty()) {
    //     cout << q.front() << " ";  // Print the front element
    //     q.pop();  // Remove the front element
    // }
    cout<<"After interleave the elements: "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}