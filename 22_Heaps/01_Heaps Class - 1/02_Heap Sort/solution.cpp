
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
    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildHeap(arr, n);
    cout<<"Printing the heap: "<<endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    heapSort(arr , n);  // Time complexity of the heap sort is O(nlogn) hoti hai.........................
     for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}