// Bubble Sort:-
//              In this technique , we just compare the two adjacent element of the array and then sort them manually by 
// swapping if not sorted . 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& var){
    int n = var.size();
    for (int i = 0; i < n-1 ; i++)
    {
        for(int j = 0; j<n-i-1 ; j++){
            if(var[j] > var[j+1]){
                swap(var[j] , var[j+1]);
            }
        }
    }
    
}
int main()
{
    vector<int> var = {50,45,24,65,11,19,12,10,4,3,2,1};
    cout<<"before sorting the array looks like: "<<endl;
    for(int i : var){
        cout<<i<<" ";
    }
    cout<<endl;
    bubbleSort(var);
    cout<<"After sorting the array looks like: "<<endl;
     for(int i : var){
        cout<<i<<" ";
    }
    return 0;
}