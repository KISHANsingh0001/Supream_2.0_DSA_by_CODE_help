//    Move all negative number to the left side in an array      

#include<iostream>
#include<vector>
using namespace std;
void moveNegative(vector<int>& v){
    int low = 0;
    int mid = 0;
    while (mid<v.size())
    {
        if(v[mid] > 0){
            mid++;
        }
        else{
            swap(v[low] , v[mid]);
            low++;
            mid++;
        }
    }
    
}
int main()
{
    int n;
    cout<<"Enter the size of the vector: "<<endl;
    cin>>n;
    vector<int> v;
    cout<<"Enter the vector elements which is positive and negative both  "<<endl;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    moveNegative(v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}