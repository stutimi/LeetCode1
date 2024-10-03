class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int remainder = total_sum % p;
        if (remainder == 0) {
            return 0; // Already divisible by p
        }

        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // To handle the case where the whole prefix gives the needed remainder
        long long prefix_sum = 0;
        int min_length = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - remainder + p) % p;
            
            if (prefix_map.find(target) != prefix_map.end()) {
                min_length = min(min_length, i - prefix_map[target]);
            }
            
            // Store the current prefix_sum modulo p with its index
            prefix_map[prefix_sum] = i;
        }

        // If we didn't find any valid subarray, return -1
        return min_length == nums.size() ? -1 : min_length;
    }
};
