class Solution
{
public:
    class comp
    {
    public:
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;
        for (auto head : lists)
        {
            if (head)
                pq.push(head);
        }

        ListNode *ansHead = new ListNode(-1);
        auto it = ansHead;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            it->next = top;
            if (top->next)
                pq.push(top->next);

            it = it->next;
        }

        return ansHead->next;
    }
};