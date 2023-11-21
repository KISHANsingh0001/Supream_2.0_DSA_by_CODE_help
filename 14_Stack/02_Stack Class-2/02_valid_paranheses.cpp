//                                        Leetcode problem number 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
#include <iostream>
#include<string>
#include <vector>
#include <stack>
using namespace std;
bool isValid(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char brackit = s[i];

        if (brackit == '(' || brackit == '{' || brackit == '[')
        {
            // simply push in the stack
            st.push(brackit);
        }
        else
        {
            if (!st.empty())
            { // yadi stack khali nahi hai
                // for closing brackit vala case
                if (brackit == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (brackit == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (brackit == ']' && st.top() == '[')
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
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
   string s = "({})";
   if(isValid(s)){
    cout<<"this is valid parentheses"<<endl;
   }
   else{
     cout<<"this is not a valid parentheses"<<endl;
   }
    return 0;
}