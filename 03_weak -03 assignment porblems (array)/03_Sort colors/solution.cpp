//       Leetcode problem number 75: Sort colors 
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same
// color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sortColors(vector<int>& v){
    int low = 0;
    int mid = 0;
    int high = v.size() -1;
    while (mid<=high)
    {
        if(v[mid]==0){
            swap(v[low] , v[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1){
            mid++;
        }
        else{
            swap(v[mid] , v[high]);
            high--;
        }

    }
    
}
int main()
{
    int n;
    cout<<"Enter the size of the vector: "<<endl;
    cin>>n;
    vector<int> v;
    cout<<"Enter the vector elements which is only 0's , 1's and 2's "<<endl;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    sortColors(v);
    cout<<"Sorted colors is given below : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}