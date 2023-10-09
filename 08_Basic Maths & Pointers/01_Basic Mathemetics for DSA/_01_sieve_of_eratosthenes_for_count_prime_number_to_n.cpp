// Leetcode (204) Count prime numbers....
#include<iostream>
#include<vector>
using namespace std;
int countPrimes(int n){
    if(n==0) return 0;
    vector<bool>prime(n , true);
    prime[0]=prime[1] = false;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if(prime[i]){
            ans++;
            int j = 2 * i;
            while (j<=n)
            {
                prime[j] = false;
                j += i;
            }
            
        }
    }
    return ans;
    
}
int main()
{
    int n = 20;
    int ans = countPrimes(n);
    cout<<"Between 2 to "<<n<<" : "<<ans<<" prime number are present."<<endl;
    
    return 0;
}