// PROGRAM 06: Optimizing Sieve of Eratosthenes
#include<iostream>
#include<vector>
#include <cmath>
using namespace std;


// ✅Optimizing Sieve of Eratosthenes --> T.C. = O(N * (log(log N))) and S.C. = O(N)
vector<bool> Sieve(int N){
    
    // Create the sieve array of N size telling isPrime or not
    vector<bool> sieve(N+1,true);
    sieve[0]=sieve[1]=false;

    // Optimization 02: replace i<=N with i*i<=N in outer loop
    for(int i=2; i*i<=N ; i++){ 
        if(sieve[i]){
            // Optimization 01: replace j = i * 2 with j =  i * i in inner loop
            // first unmarked number would be i*i, as others have been marked by 2 to (i-1)
            int j = i*i;
            while( j<=N){ 
                sieve[j]=false;
                j+=i;
            }
        }
    }
    
    return sieve;
}

int main(){
    int N = 25;
    vector<bool> sieve = Sieve(N);
    cout<<"Prime Numbers are:"<<endl;
    for(int i=0;i<=N;i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}