#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void insertionSort(vector<int>& var){
    int n = var.size();
    
    for(int i = 1 ; i<n ; i++){
        int key = var[i];
       int j = i-1;
       // move elements of var[0..i-1] that are greater then key to 
       // to one position ahead of their current position
       while (j>=0 && var[j] > key)
       {
        var[j+1] = var[j--];
       }
       var[j+1] = key;
    }
}

int main()
{
    vector<int> var = {44,333,22,1,11,1,2,3,11111};
    cout<<"before sorting the array looks like: "<<endl;
    for(int i : var){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    insertionSort(var);
    cout<<"After sorting the array looks like: "<<endl;
     for(int i : var){
        cout<<i<<" ";
    }
    return 0;
}