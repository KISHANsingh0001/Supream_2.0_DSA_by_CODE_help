#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 vector<int>twoPointerApproch(vector<int>& arr , int k , int x){
        int l = 0 , h = arr.size()-1;
        while(h-l>=k){
            if(x-arr[l] > arr[h] - x){
                l++;
            }
            else{
                h--;
            }
        }
        return vector<int>(arr.begin()+l , arr.begin()+h+1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointerApproch(arr , k , x);
    }
int main()
{
    vector<int>arr = {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4;
    int x = 35;
    vector<int> ans = findClosestElements(arr , k , x);
    cout<<k<<" elements which is closed to "<<x<<" is: "<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}