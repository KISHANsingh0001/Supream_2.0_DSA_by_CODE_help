// Why it takes O(N) Time complexity
// For each non-leaf node, there is a constant amount of work done (comparisons and swaps) during the heapify operation.
// The number of non-leaf nodes in a binary heap of size n is approximately n/2. This is because a binary heap is a 
// complete binary tree, and the number of leaves is roughly half of the total number of nodes.
// Therefore, the number of operations for each non-leaf node is constant.
#include <iostream>
using namespace std;

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;

    // check in left
    if (leftIndex <= n && arr[largestIndex] < arr[leftIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex <= n && arr[largestIndex] < arr[rightIndex])
    {
        largestIndex = rightIndex;
    }
    if (index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        //index = largestIndex;
        heapify(arr, n, largestIndex);
    }
}

void buildHeap(int arr[], int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}
void heapSort(int arr[] , int n){
    while (n!=1)
    {
        swap(arr[1] , arr[n]);
        n--;
        heapify(arr , n , 1);
    }
    
}

int main()
{
    //  IMP NOTE:- O(N) Size ke array ko ager heap main conver karna hai to uski time complxity O(N) hoti hai..........
    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildHeap(arr, n);
    cout<<"Printing the heap: "<<endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    heapSort(arr , n);
     for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}