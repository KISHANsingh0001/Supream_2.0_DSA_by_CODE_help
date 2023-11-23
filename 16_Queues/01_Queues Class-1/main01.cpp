//                                             implimentation of the queue data structure
#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    { // paramitirized CTOR
        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    // push opration
    void push(int val)
    {
        // overFlow vala case
        if (rear == size - 1)
        {
            cout << "OVERFLOW Queue" << endl;
            return;
        }
        // empty vala case (for inserting the single element)
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // normal case
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    // pop opration
    void pop()
    {
        // UNDERFLOW vala case
        if (front == size - 1)
        {
            cout << "UNDERFLOW Queue" << endl;
            return;
        }
        // Single element pop
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // normal case
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    // get size of the queue
    int getSize()
    {
        // alrady empty vala case
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else
        {
            return rear - front + 1;
        }
    }
    // check Queue is empty or not
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // get rear element
    int getRear()
    {
        if (rear == -1)
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    void printQ()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(4);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    cout << "Size of the Queue is: " << q.getSize() << endl;
    q.printQ();
    q.pop();
    cout << "Size of the Queue is: " << q.getSize() << endl;
    cout << "Rear element of the Queue: " << q.getRear() << endl;
    return 0;
}