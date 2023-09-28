// leet code question number 74. search a 2d matrix
#include<iostream>
#include<vector>
using namespace std;
bool searchIn2DMatrix(vector<vector<int>>& mat , int target){
    int row = mat.size();
    int col = mat[0].size();
    int total = row*col;
    int s = 0;
    int e = total - 1;
    while(s<=e){
        int mid = s+(e-s)/2;
        int currenEle = mat[mid/col][mid%col];
        if(currenEle == target){
            return true;
        }
        else if(currenEle > target){
            e= mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    bool ans = searchIn2DMatrix(mat , 14);
    if(ans){
        cout<<"Target is found ";
    }
    else{
        cout<<"Target is not found ";
    }
    return 0;
}