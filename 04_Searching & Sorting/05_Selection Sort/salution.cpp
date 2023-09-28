// Selection Sort :- 1) first of all , we will find the smallest element of an array and swap that 
//                      with the element at index 0 
//                   2) similarly we will find the second smallest element and swap the with element 
//                      at index 1 an so on.                
//                   3) ultimately , we will be getting a sorted array in increasing order only

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void selectionSort(vector<int>& var){
    
    int n = var.size();
    for(int i = 0 ; i<n-1 ; i++){
        int minIndex = i; // ith element hi smallest element hai
        for(int j = i+1 ; j < n ; j++){
            if(var[j] < var[minIndex]){
                minIndex = j;
            }
        }
        // swap ith and minIndex element....
        swap(var[i] , var[minIndex]);
    }
}

int main()
{
    vector<int> var = {50,45,24,65,11,19,12,10,4,3,2,1};
    cout<<"before sorting the array looks like: "<<endl;
    for(int i : var){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    selectionSort(var);
    cout<<"After sorting the array looks like: "<<endl;
     for(int i : var){
        cout<<i<<" ";
    }
    return 0;
}