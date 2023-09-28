// Binary search in nearly sorted array 
#include<iostream>
using namespace std;
int searchNearlySorted(int arr[] , int n , int target){
    int s = 0 ;
    int e = n - 1;
    int mid = s +(e-s)/2;
    while (s<=e)
    {
        if(mid-1 >=0 && arr[mid - 1] == target){
            return mid;
        }
        else if(arr[mid]==target){
            return mid;
        }
        else if(mid+1 < n && arr[mid+1] == target){
            return mid;
        }
        else if(target > arr[mid]){
            s = mid + 2;
        }
        else{
            e = mid - 2;
        }
        mid = s+(e-s)/2;
    }
    return -1;
    
}
int main()
{
    int arr[7] = {20,10,30,50,40,70,60};
    int n = 7;
    int target = 50;

    int ans = searchNearlySorted(arr , n , target);
    cout<<"element is present in "<<ans<<" index";
   
    return 0;
}