// you have to allocate the book to m students such that the maximum number of pages assigned to a student is minimum"
#include<iostream>
#include<numeric> // accumulate function includes in this library
using namespace std;
bool isPossibleSolution(int arr[] , int n , int m , int sol){
    int pageSum = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > sol){
            return false;
        }
        if(pageSum + arr[i] > sol){
            c++;
            pageSum = arr[i];
            if(c>m){
                return false;
            }
        }
        else{
            pageSum+=arr[i];
        }
    }
    return true;
    
}
int findPages(int arr[] , int n , int m){
    if(m>n){
        return  1;
    }
    int s = 0 , ans =  1;;
    int e = accumulate(arr , arr+n , 0); // this function gives sum of all elements of the array
    while (s<=e)
    {
        int mid = (s + e)>>1;
        if(isPossibleSolution(arr , n , m , mid)){
            ans = mid;
            e = mid   1; // for minimizing the answer 
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
    
    
}
int main()
{
    int arr[] = {12,34,67,90};
    int n = 4;
    int m = 2;
    int ans = findPages(arr , n , m);
    cout<<"Answer is : "<<ans;
    return 0;
}