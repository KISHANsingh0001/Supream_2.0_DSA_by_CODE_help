                                
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the row: ";
    cin>>n;
    for(int row = 0 ; row<n ; row++){
        // loop for printing spaces 
        for(int col = 0 ; col<n-row-1 ; col++){
           cout<<" ";
        }
        // for printing stars 
        for(int col = 0 ; col < row+1 ; col++){
        cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}