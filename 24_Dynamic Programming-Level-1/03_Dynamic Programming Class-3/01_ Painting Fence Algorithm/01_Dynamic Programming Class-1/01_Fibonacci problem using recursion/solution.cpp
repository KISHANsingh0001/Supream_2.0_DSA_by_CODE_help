#include<iostream>
using namespace std;
 int solveUsingRecursion(int n) {
        //base case
        if(n == 0)
            return 0;
        if(n == 1) {
            return 1;
        }
        //recursive relation
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return ans;
    }
int main()
{
    int n = 6;
    cout<<n<<"'th fibonacci number is: "<<solveUsingRecursion(n);
    return 0;
}