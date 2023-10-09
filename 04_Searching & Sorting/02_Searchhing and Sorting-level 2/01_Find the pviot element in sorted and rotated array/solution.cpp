//                                               leet code problem number 33.
#include<iostream>
#include<vector>
using namespace std;
   int findPivotIndex(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            //corner case
            if(s == e) {
                //single element
                return s;
            }

            if(mid+1 < n && arr[mid] > arr[mid+1])
                return mid;
            else if(mid-1 >=0 && arr[mid] < arr[mid-1])
                return mid-1;
            else if(arr[s] > arr[mid] ) 
                e = mid - 1;
            else 
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
        return -1;

    }

    int binarySearch(vector<int>& arr, int s, int e, int target) {
        int mid = s + (e-s)/2;
        while(s<=e) {
            if(arr[mid] == target) {
                return mid;
            }
            if(target > arr[mid]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        //cout << "Pivot Index us: " << pivotIndex << endl;
        int n = nums.size();
        int ans = -1;

        //search in A
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else {
            ans = binarySearch(nums, pivotIndex+1, n-1, target);
        }
        return ans;
    }
int main()
{
    vector<int> v={4,5,6,7,0,1,2};
    int target = 0;
    int ans = search(v,target);
    cout<<"Target is present at index : "<<ans<<endl;
    return 0;
}