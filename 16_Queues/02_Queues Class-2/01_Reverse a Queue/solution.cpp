#include <iostream>
#include<queue>
using namespace std;
// reverse using recursion 
void reverseQueue(queue<int> &q)
{
    // Base case
    if (q.empty())
    {
        return;
    }
    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp); // backtraking
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverseQueue(q);
    for(int i = 0 ; i<5 ; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    

    return 0;
}