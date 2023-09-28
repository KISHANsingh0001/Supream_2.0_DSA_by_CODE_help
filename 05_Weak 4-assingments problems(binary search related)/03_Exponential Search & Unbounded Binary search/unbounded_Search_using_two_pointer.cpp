#include<iostream>
using namespace std;
int binarySearch(int a[] , int s , int e , int x){
    while(s<=e){
        int mid = s +(e-s)/2;
        if(a[mid] == x) return mid;

        else if(x > a[mid]){
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
    }
    return -1;
}
int expSearch(int a[] , int n , int x){
    int i = 0;
    int j = 1;
    while( a[j] < x){
        i=j;
        j= j * 2;
    }
    return binarySearch(a , i , j , x);
}
int main()
{
    int a[] = {3,4,5,6,11,13,14,15,56,70,90};
    int n = 11;
    int x = 90;
    int ans = expSearch(a , n , x);
    cout<<"Our target is present in "<< ans <<" index."<<endl;
    return 0;
}