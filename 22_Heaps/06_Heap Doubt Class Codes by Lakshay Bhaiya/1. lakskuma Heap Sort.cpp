class Solution
{
public:
    void heapify(vector<int> &v, int i, int &n)
    {
        while (1)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int swapindex = i;
            if (left < n && v[left] > v[i])
            {
                swapindex = left;
            }
            if (right < n && v[right] > v[swapindex])
            {
                swapindex = right;
            }
            if (swapindex == i)
                break;

            swap(v[i], v[swapindex]);
            i = swapindex;
        }
    }

    void buildHeap(vector<int> &v, int n)
    {
        for (int i = (n / 2) - 1; i >= 0; --i)
            heapify(v, i, n);
    }

    void HeapSort(vector<int> &nums)
    {
        int n = nums.size() - 1;
        while (n > 0)
        {
            // swap element to last
            swap(nums[0], nums[n]);
            heapify(nums, 0, n);
            n--;
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        buildHeap(nums, nums.size());
        HeapSort(nums);
        return nums;
    }
};