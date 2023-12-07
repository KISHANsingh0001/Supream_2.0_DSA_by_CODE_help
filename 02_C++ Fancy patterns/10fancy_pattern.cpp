#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int row = 0; row < n ; row++){
        for (int col = 0; col < row+1 ; col++)
        {
            char ch = col + 1 + 'A' -1;
            cout<<ch ;
        }
        cout<<endl;
        
    }
    return 0;
}