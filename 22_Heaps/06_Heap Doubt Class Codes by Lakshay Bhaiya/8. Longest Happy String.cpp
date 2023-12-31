class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        // make PQ.
        priority_queue<pair<int, char>> pq;

        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        // build answer string
        string ans;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            if (ans.size() == 0 || ans.back() != top.second)
            {
                // add at most 2 freq. of maximum freq. char
                int times = min(top.first, 2);
                for (int i = 0; i < times; ++i)
                    ans += top.second;
                top.first -= times;
                if (top.first > 0)
                    pq.push(top);
            }
            else if (!pq.empty())
            {
                // add at most 1 freq. of maximum freq. char
                auto top2 = pq.top();
                pq.pop();
                ans += top2.second;
                top2.first--;
                if (top2.first > 0)
                {
                    pq.push(top2);
                }
                // return to the pq the max char we popped out in if clause:
                pq.push(top);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};