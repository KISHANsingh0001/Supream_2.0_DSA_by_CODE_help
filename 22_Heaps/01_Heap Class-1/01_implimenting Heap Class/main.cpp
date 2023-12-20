
#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        // size = current number of elements in heap
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap OverFlow" << endl;
            return;
        }
        // size increase kar jaega
        size++;
        int index = size;
        arr[index] = val;

        /// take the val to its cvorrect position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int deleteFromHeap()
    {
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // last element ko delete uski original position se
        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // find out karna h , sabse bada kon
            int largestKaIndex = index;
            // check left child
            if (leftIndex <= size && arr[largestKaIndex] < arr[leftIndex])
            {
                largestKaIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestKaIndex] < arr[rightIndex])
            {
                largestKaIndex = rightIndex;
            }
            // no change
            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return answer;
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// void heapify(int *arr, int n, int index) {
//   int leftIndex = 2*index;
//   int rightIndex = 2*index+1;
//   int largestKaIndex = index;

//   //teno me se max lao
//   if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]) {
//     largestKaIndex = leftIndex;
//   }
//   if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) {
//     largestKaIndex = rightIndex;
//   }
//   //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3
//   if(index != largestKaIndex) {
//     swap(arr[index], arr[largestKaIndex]);
//     //ab recursion sambhal lega
//     index = largestKaIndex;
//     heapify(arr, n, index);
//   }
// }

int main()
{
    Heap h(20);
    //insertion
    h.insert(100);
    h.insert(4);
    h.insert(3);
    h.insert(1);
    h.insert(500);
      h.printHeap();
      int ans = h.deleteFromHeap();
      cout<<"Answer is: "<<ans<<endl;
      h.printHeap();
      int ans1 = h.deleteFromHeap();
      cout<<"Answer is: "<<ans1<<endl;
      h.printHeap();

    cout << "Printing the content of heap: " << endl;
    h.printHeap();
    int ans = h.deleteFromHeap();
    cout << "Answer: " << ans << endl;
    cout << "Printing the content of heap: " << endl;
    h.printHeap();
    return 0;
}