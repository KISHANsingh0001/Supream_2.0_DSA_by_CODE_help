https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


#include <bits/stdc++.h>
using namespace std;

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // step1: push all persons into the stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // step 2: run discard method to get a mightBeCelebrity
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if a b ko janta hai
        if (M[a][b])
        {
            // a is not a celebrity. b might be
            st.push(b);
        }
        else
        {
            // b is not a celebrity . a might be
            st.push(a);
        }
    }
    // step 3: check that single perrson is actully celebrity
    int mightBeCel = st.top();
    st.pop();
    // cel should not know anyone
    for (int i = 0; i < n; i++)
    {
        if (M[mightBeCel][i] != 0)
        {
            return -1;
        }
    }
    // everyone should know cel
    for (int i = 0; i < n; i++)
    {
        if (M[i][mightBeCel] == 0 && i != mightBeCel)
        {
            return -1;
        }
    }
    return mightBeCel;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
    return 0;
}

