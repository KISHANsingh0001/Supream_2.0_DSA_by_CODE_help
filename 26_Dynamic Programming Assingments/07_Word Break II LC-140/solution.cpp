#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// Method 1 : SolveUsing Recursion Approch
vector<string> solveUsingRec(string &s, unordered_map<string, bool> &dict, int i)
{
    // Base case
    if (i == s.size())
        return {""};
    vector<string> ans;
    string word;

    for (int j = i; j < s.size(); j++)
    {
        word.push_back(s[j]);
        if (dict.find(word) == dict.end())
            continue;

        // Found a valid string
        auto right = solveUsingRec(s, dict, j + 1);
        for (auto eachPart : right)
        {
            string endPart;
            if (eachPart.size() > 0)
                endPart = " " + eachPart;
            ans.push_back(word + endPart);
        }
    }
    return ans;
}
// Method 2 : SolveUsing Recursion + Memoization(Top down dp) Approch
unordered_map<int, vector<string>> dp;
vector<string> solveUsingMem(string &s, unordered_map<string, bool> &dict, int i)
{
    // Base case
    if (i == s.size())
        return {""};
    if (dp.find(i) != dp.end())
        return dp[i];
    vector<string> ans;
    string word;

    for (int j = i; j < s.size(); j++)
    {
        word.push_back(s[j]);
        if (dict.find(word) == dict.end())
            continue;

        // Found a valid string
        auto right = solveUsingMem(s, dict, j + 1);
        for (auto eachPart : right)
        {
            string endPart;
            if (eachPart.size() > 0)
                endPart = " " + eachPart;
            ans.push_back(word + endPart);
        }
    }
    dp[i] = ans;
    return dp[i];
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> dict;
    for (auto word : wordDict)
        dict[word] = true;

    return solveUsingMem(s, dict, 0);
}
int main()
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> ans = wordBreak(s, wordDict);
    for (auto str : ans)
    {
        cout << str << "  ";
    }
    cout << endl;
    return 0;
}