// Leet code problem number 287 : Find the duplicate element 

#include<iostream>
#include<vector>
using namespace std;
int duplicateElement(vector<int>& nums){   // positioning method 
    while(nums[0] != nums[nums[0]]){
       swap(nums[0] , nums[nums[0]]);
    }
    return nums[0];
}
int main()
{
   int n;
    cout<<"Enter the size of the vector: "<<endl;
    cin>>n;
    vector<int> v;
    cout<<" Enter the vector elements "<<endl;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    int ans = duplicateElement(v); 
    cout<<"Duplicate element is : "<<ans<<endl;
    return 0;
}