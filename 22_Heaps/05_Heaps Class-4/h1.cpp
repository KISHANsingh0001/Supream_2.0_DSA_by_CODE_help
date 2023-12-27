class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int i=0; i<piles.size(); i++) {
            int element = piles[i];
            maxHeap.push(element);
        }

        while(k--) {
            int topElement = maxHeap.top();
            maxHeap.pop();

            topElement = topElement - topElement/2;

            maxHeap.push(topElement);
        }

        int sum = 0;
        while(!maxHeap.empty()) {
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }
        return sum;
        
    }
};