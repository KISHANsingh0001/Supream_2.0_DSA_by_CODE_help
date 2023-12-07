//                                    1 
//                                    1 1
//                                    1 2 1
//                                    1 3 3 1
//                                    1 4 6 4 1
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        int c = 1;
        for (int j = 1; j <= i; j++)
        {
            cout<<c<<" ";
            c = c * (i - j)/ j;
        }
        cout<<endl;
        
    }
    
    return 0;
}