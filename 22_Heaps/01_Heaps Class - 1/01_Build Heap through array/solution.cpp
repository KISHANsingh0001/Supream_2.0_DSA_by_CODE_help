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
        index = largestIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}

int main()
{
    //  IMP NOTE:- O(N) Size ke array ko ager heap main conver karna hai to uski time complxity O(N) hoti hai..........
    int arr[8] = {-1, 45, 23, 42, 13, 53, 13, 52};
    int n = 8;
    buildHeap(arr, n);
    for (int i = 1; i <= 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}