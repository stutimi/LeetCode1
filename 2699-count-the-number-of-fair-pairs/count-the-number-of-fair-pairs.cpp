#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        // Sort the array for the two-pointer approach
        std::sort(nums.begin(), nums.end());
        
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            int min_val = lower - nums[i];
            int max_val = upper - nums[i];
            
            // Find the range of indices for j
            auto low = std::lower_bound(nums.begin() + i + 1, nums.end(), min_val);
            auto high = std::upper_bound(nums.begin() + i + 1, nums.end(), max_val);
            
            count += high - low;  // Number of valid pairs for this i
        }
        
        return count;
    }
};

