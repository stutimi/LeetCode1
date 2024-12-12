class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        std::priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        while (k--) {
            int maxGifts = maxHeap.top();
            maxHeap.pop();
            int remainingGifts = std::floor(std::sqrt(maxGifts));
            maxHeap.push(remainingGifts);
        }
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }
        
        return totalGifts;
    }
};
