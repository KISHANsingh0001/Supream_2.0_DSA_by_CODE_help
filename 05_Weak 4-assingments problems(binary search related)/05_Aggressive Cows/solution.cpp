// You are given an array consisting of n integers which denote the position of a stall.
// You are also given an integer k which denotes the number of aggressive cows. You are given the task of
// assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 bool isPossibleSolution(vector<int>& stalls , int k , int mid){
        // can we place k cows with at least mid distance between cows
        int c = 1;
        int pos = stalls[0];
        
        for(int i = 1 ; i<stalls.size() ; i++){
            if(stalls[i] - pos >=mid){
                c++;
                pos=stalls[i]; // one more cow has been placed
            }
            if(c==k){
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin() , stalls.end());
        int s = 0;
        int e = stalls[stalls.size() -1] - stalls[0];
        int ans = -1;
        
        while(s<= e){
            int mid = s+(e-s)/2;
            if(isPossibleSolution(stalls , k , mid)){
                ans = mid;
                s = mid + 1; // we maximize the answer that's why
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
int main()
{
    vector<int> stalls = {1,2,4,8,9};
    int n = stalls.size();
    int k = 3;
    int ans = solve(n , k , stalls);
    cout<<"Minimum distance between cows is: "<<ans<<endl;
    return 0;
}