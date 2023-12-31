class MedianFinder
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.size() == 0 || num < maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

        // both heaps must have same no_of_elements.
        // if not, max heap must have 1 more element than minheap
        if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        // non matching case
        // phle se hi maintained hai ke, maxheap me hoga answer.
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */