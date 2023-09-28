//                                           First Repeating Element
// Given an array arr[] of size n, find the first repeating element. 
// The element should occur more than once and the index of its first
//  occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 
#include<iostream>
#include<unordered_map>
using namespace std;
int firstRepeated(int arr[], int n) {
        unordered_map<int , int > hash;
        for(int i = 0 ; i<n ;i++){
            hash[arr[i]]++;
        }
        for(int i = 0 ; i< n ; i++){
            if(hash[arr[i]] > 1){
                return i+1;
            }
        }
        return -1;
    }
int main()
{
    int n;
    int arr[] = {1,5,3,4,3,5,6};
    n = sizeof(arr)/sizeof(int);
    int ans = firstRepeated(arr , n);
    cout<<"First repeating array index is (1 based indexing) : "<<ans<<endl;
    return 0;
}