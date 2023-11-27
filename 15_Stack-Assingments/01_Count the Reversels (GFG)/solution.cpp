// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

// Given a string S consisting of only opening and closing curly brackets '{' and '}',
//  find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

#include<bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    // if odd sized string then impossible to make pairs
    if(s.size() & 1) return -1;
    
    stack<char> st;
    int ans = 0 ;
    for(char ch: s){
        if(ch =='{'){
            st.push(ch);
            
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    
    while(!st.empty()){
        char a = st.top() ; st.pop();
        char b = st.top() ; st.pop();
        if(a==b){
            ans+=1;
        }
        else{
            ans+=2;
        }
    }
    return ans;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
    return 0;
}





