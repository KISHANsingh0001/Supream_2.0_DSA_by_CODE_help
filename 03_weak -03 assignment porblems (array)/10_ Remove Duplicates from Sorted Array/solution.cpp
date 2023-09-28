// leet code problem number 26. Remove Duplicates from Sorted Array
//                                                                   Input: nums = [1,1,2]
//                                                                   Output: 2, nums = [1,2,_]
#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums){
    int j = 0;
    for(int i = 1 ; i<nums.size(); i++){
        if(nums[i]!=nums[i-1]){
            nums[++j] = nums[i];
        }
    }
    return j+1;
}
int main()
{
    int n;
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    cout << "Enter the vector elements: " << endl;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }
    int ans = removeDuplicates(nums);
    cout<<"unique element in this array is: "<<ans <<endl;
    return 0;
}