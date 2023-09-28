// Missing Elements from an array with Duplicates where n = size of array 
// 1 based indexing will be taken ..              input - [1, 2, 3, 4, 4, 7, 7]
//                                               output - 5 , 6 (missing number)
#include<iostream>
using namespace std;
void findMissing(int arr[] , int n){
    // vested method 
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]);
        if(arr[index - 1] > 0){
            arr[index - 1] *= -1;
        }
    }
    cout<<"Missing element is: ";
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0){
            cout<<i+1<<" ";
        }
    }
    
    
}
int main()
{
    int n;
    int arr[]={1, 2, 3, 4, 4, 7, 7};
    n = sizeof(arr)/sizeof(int);
    findMissing(arr , n);
    return 0;
} 