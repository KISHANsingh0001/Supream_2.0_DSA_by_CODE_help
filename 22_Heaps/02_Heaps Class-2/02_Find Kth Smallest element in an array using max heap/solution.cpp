#include <iostream>
#include <queue>

using namespace std;
int getKthSmallestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int> pq;
    // insert inital k elements of array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements, push only if they are less than top
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int main()
{
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 5;
    int ans = getKthSmallestElement(arr, n, k);
    cout << "Ans is: " << ans << endl;
    return 0;
}