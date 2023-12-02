#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValid(string s)
{
    // edge case
    if (s[0] != 'a')
        return false;
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b')
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.push(ch);
            }
            else
            {
                return false;
            }
        }
        else
        { // ch =='c'
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty() ? true : false;
}
int main()
{
   string s = "abcacababcc";
   if(isValid(s)){
      cout<<"Word is valid "<<endl;
   }
   else{
    cout<<"Word is not valid "<<endl;
   }
    return 0;
}