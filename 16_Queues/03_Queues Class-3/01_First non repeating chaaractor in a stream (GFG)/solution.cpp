
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        string ans;
        queue<char> q;
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            freq[ch - 'a']++;
            q.push(ch);

            while (!q.empty())
            {
                char frontCharactor = q.front();
                if (freq[frontCharactor - 'a'] > 1)
                {
                    // this is not a answer
                    q.pop();
                }
                else
                {
                    ans.push_back(frontCharactor);
                    break;
                }
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
