#include <vector>
#include <queue>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Step 1: Create a max heap (using priority queue in C++)
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long score = 0; // To store the final score
        
        // Step 2: Perform k operations
        for (int i = 0; i < k; ++i) {
            int maxElement = maxHeap.top(); // Get the maximum element
            maxHeap.pop();                  // Remove the top element
            
            score += maxElement;            // Add the maximum element to the score
            
            // Step 3: Replace maxElement with ceil(maxElement / 3) and push it back into the heap
            maxHeap.push((maxElement + 2) / 3);
        }
        
        return score;
    }
};
