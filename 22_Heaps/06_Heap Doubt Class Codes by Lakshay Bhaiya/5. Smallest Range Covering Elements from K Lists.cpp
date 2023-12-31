class Solution
{
public:
    class info
    {
    public:
        int val, vec_in, index;
        info(int x, int y, int z) : val(x), vec_in(y), index(z){};
    };

    class comp
    {
    public:
        bool operator()(info &a, info &b)
        {
            return a.val > b.val;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &v)
    {
        vector<int> ans;
        int maxx = INT_MIN;
        priority_queue<info, vector<info>, comp> pq;
        for (int i = 0; i < v.size(); i++)
        {
            auto vi = v[i]; // ith vector
            pq.push({vi[0], i, 0});
            maxx = max(maxx, vi[0]);
        }

        ans.push_back(pq.top().val); // min
        ans.push_back(maxx);         // max

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            if (maxx - top.val < ans[1] - ans[0])
            {
                ans[0] = top.val;
                ans[1] = maxx;
            }

            if (top.index + 1 < v[top.vec_in].size())
            {
                pq.push({v[top.vec_in][top.index + 1], top.vec_in, top.index + 1});
                maxx = max(maxx, v[top.vec_in][top.index + 1]);
            }
            else
                break;
        }
        return ans;
    }
};