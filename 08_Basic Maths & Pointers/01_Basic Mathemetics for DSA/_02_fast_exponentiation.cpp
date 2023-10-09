// we have to find the a to the power b ..
#include<iostream>
using namespace std;
int fastExponentiation(int a , int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            // odd case
            ans = ans * a;
        }
        a = a*a;
        b>>=1;
    }
    return ans;
}
int main()
{
    int a = 2;
    int b = 8;
    int ans = fastExponentiation(a , b);
    cout<<a<<" to the power "<<b<<" is : "<<ans;
    return 0;
}