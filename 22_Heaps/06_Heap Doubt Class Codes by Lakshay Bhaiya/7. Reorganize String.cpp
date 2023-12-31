class Solution
{
public:
    string reorganizeString(string s)
    {
        // create freq map
        map<char, int> freqMap;
        for (auto ch : s)
        {
            freqMap[ch]++;
        }

        // make PQ.
        priority_queue<pair<int, char>> pq;
        for (auto it : freqMap)
        {
            pq.push({it.second, it.first});
        }

        // build answer string
        string ans;
        pair<int, char> hidden = {0, 0};
        while (!pq.empty())
        {
            if (ans.size() == 0)
            {
                hidden = pq.top();
                pq.pop();
                ans += hidden.second;
                hidden.first--;
            }
            else
            {
                auto top = pq.top();
                pq.pop();
                ans += top.second;
                top.first--;
                if (hidden.first > 0)
                    pq.push(hidden);
                hidden = top;
            }
        }
        if (ans.size() != s.size())
            return "";
        return ans;
    }
};