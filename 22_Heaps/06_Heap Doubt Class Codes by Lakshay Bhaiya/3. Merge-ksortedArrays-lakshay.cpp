class Solution
{
public:
    // Function to merge k sorted arrays.

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

    vector<int> mergeKArrays(vector<vector<int>> v, int K)
    {
        vector<int> ans;
        priority_queue<info, vector<info>, comp> pq;
        for (int i = 0; i < K; i++)
        {
            auto vi = v[i];
            pq.push({vi[0], i, 0});
        }

        while (!pq.empty())
        {
            auto front = pq.top(); // gives min
            pq.pop();
            ans.push_back(front.val);

            if (front.index + 1 < v[front.vec_in].size())
                pq.push({v[front.vec_in][front.index + 1], front.vec_in, front.index + 1});
        }
        return ans;
    }
};