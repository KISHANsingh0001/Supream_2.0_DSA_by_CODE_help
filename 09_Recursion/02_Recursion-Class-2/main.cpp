#include <iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

// Printing the array using recursion???
// void print(int *arr , int size , int index){
//   if(index>=size){
//     return;
//   }
 
//   print(arr , size , index+1);
//    cout<<arr[index]<<" ";
// }
//...............................................................................
// linear Search using recursion???
// int linearSearch(int arr[] , int size , int index , int target){
//     if(index>=size){
//       return -1;
//     }
//     if(arr[index] == target){
//       return index;
//     }
//     linearSearch(arr , size , index+1 , target);

// }
//................................................................................................

// Binary search  using recursion???? 
// bool binarySearch(int arr[] , int s , int e , int target){
//   if(s>e){
//     return false;
//   }
//   int mid = s+(e-s)/2;
//   if(arr[mid] == target){
//     return true;
//   }
//   if(arr[mid] > target){
//     e = mid - 1;
//   }
//   if(arr[mid] < target){
//     s = mid + 1;
//   }
//   binarySearch(arr , s , e , target);
// }
//...............................................................................................

// find the even number in an array???
//  void solve(int arr[] , int size , int index ,  vector<int>& ans ){
//   if(index>=size){
//     return;
//   }

//   if(arr[index] % 2 == 0){
//     ans.push_back(arr[index]);
//   }
//   solve(arr , size , index+1 , ans);
//  }

//................................................................................................

  // Printing double of the array elements???
  // void doubleElement(int arr[] , int size , int index){
  //   if(index >= size){
  //     return;
  //   }
  //   arr[index] = arr[index] * 2;
  //   doubleElement(arr , size , index+1);
  // }
//....................................................................................................

// Find the maximum number in an array using recursion???
// int maximumNum(int arr[] , int size , int index , int &maxi){
//   if(index >= size){
//     return maxi;
//   }
//   maxi = max(maxi , arr[index]);

//   maximumNum(arr , size , index+1 , maxi);
// }

//...................................................................................................

// Printing all occurances of the target element............
//   void printAllOcc(int arr[] , int size , int index , int target){
//     if(index>=size){
//       return;
//     }
//     if(arr[index] == target){
//       cout<<index<<" ";
//     }
//     printAllOcc(arr , size , index+1 , target);

// }
//.........................................................................................
void PrintingDigitsOftheNumber(int n, vector<int>& ans){
   if(n==0){
    return;
   }
    ans.push_back(n%10);
    n = n/10;
   solve(n , ans);
}
int main() {
   int arr[5] = {10,10,20,30,10};
   int size = 5;
   //print(arr , 5 , 0);
  // cout<<"found index is: "<<linearSearch(arr , 5 , 0 , 90);
   //cout<<binarySearch(arr , 0 , 5 , 9);
   //vector<int>ans;
  // solve(arr , size , 0 , ans);
  // doubleElement(arr , size , 0);
  //  for(auto i: arr){
  //   cout<<i<<" ";
  //  }
  //int maxi = INT_MIN;
  //doubleElement(arr , size , 0 , maxi);
  //maximumNum(arr , size , 0 , maxi);
  //cout<<maxi;
  //printAllOcc(arr , size , 0 , 10);
  // int n = 256;
  // solve(n , ans);
  // reverse(ans.begin() , ans.end());
  //   for(auto i: ans){
  //   cout<<i<<" ";
  //  }
  
  return 0;
}