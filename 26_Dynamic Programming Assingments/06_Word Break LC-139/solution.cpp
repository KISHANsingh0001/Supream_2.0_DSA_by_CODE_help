#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check(vector<string> &wordDict, string &s)
{
    bool flag = false;
    for (auto it : wordDict)
    {
        if (s == it)
            flag = true;
    }
    return flag;
}
// Method 1 : SolveUsing Recursion Approch
bool solveUsingRec(string &s, vector<string> &wordDict, int start)
{
    if (start == s.size())
        return true;

    // one case , nake a string
    string word = "";
    bool flag = false;
    for (int i = start; i < s.size(); ++i)
    {
        word += s[i];
        if (check(wordDict, word))
        {
            flag = flag || solveUsingRec(s, wordDict, i + 1);
        }
    }
    return flag;
}
// Method 2 : SolveUsing Recursion + Memoization(Top down dp) Approch
bool solveUsingMem(string &s, vector<string> &wordDict, int start,
                   vector<int> &dp)
{
    if (start == s.size())
        return true;

    if (dp[start] != -1)
    {
        return dp[start];
    }
    // one case , nake a string
    string word = "";
    bool flag = false;
    for (int i = start; i < s.size(); ++i)
    {
        word += s[i];
        if (check(wordDict, word))
        {
            flag = flag || solveUsingMem(s, wordDict, i + 1, dp);
        }
    }
    dp[start] = flag;
    return dp[start];
}
// Method 3 : SolveUsing Tabulation (Bottom Up dp) Approch
bool solveUsingTabu(string &s, vector<string> &wordDict)
{
    // 1 create a dp array
    vector<int> dp(s.size() + 1, 0);
    dp[s.size()] = 1;
    for (int start = s.size() - 1; start >= 0; start--)
    {
        // one case , nake a string
        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); ++i)
        {
            word += s[i];
            if (check(wordDict, word))
            {
                flag = flag || dp[i + 1];
            }
        }
        dp[start] = flag;
    }
    return dp[0];
}
int main()
{
    string s = "leetcode";
    vector<string>wordDict = {"leet","code"};
    if(solveUsingTabu(s , wordDict)){
        cout<<"S string can be space-separated"<<endl;
    }
    else{
        cout<<"Can not be space-separated"<<endl;
    }
    return 0;
}