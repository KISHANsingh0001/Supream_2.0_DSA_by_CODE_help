#include <bits/stdc++.h>

using namespace std;
void PintFirstNeg(int *arr, int n, int k = 3)
{
    deque<int> dq;
    // process first k elements
    for (int i = 0; i < k; i++)
    {
        int ele = arr[i];
        if (ele < 0)
            dq.push_back(i);
    }
    // print ans

    // process remaining window
    //  ->removal and addition
    for (int i = k; i < n; i++)
    {
        if (dq.empty())
            cout << "0" << endl;
        else
        {
            cout << arr[dq.front()] << " ";
        }
        // purani window ka ans->
        // cout << arr[dq.front()] << " ";
        // removal
        // out of range index ko q mai se remove krdo

        if (i - dq.front() >= k)
            dq.pop_front();

        // addition
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // last window ka alag se process kro
    if (dq.empty())
        cout << "0" << endl;
    else
    {
        cout << arr[dq.front()] << " ";
    }
    cout << endl;
}
int main()
{    // sliding window
    int arr[7] = {2, -5, 4, -1, -2, 0, 5};
    int n = 7;
    int k = 3;
    PintFirstNeg(arr, n, k);
    return 0;
}