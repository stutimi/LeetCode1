class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> window;
        long long maxSum = 0; 
        long long currentSum = 0; 
        int start = 0; 

        for (int end = 0; end < nums.size(); ++end) {
        
            while (window.count(nums[end])) {
                
                currentSum -= nums[start];
                window.erase(nums[start]);
                ++start;
            }

            window.insert(nums[end]);
            currentSum += nums[end];

            if (end - start + 1 == k) {
                maxSum = max(maxSum, currentSum);
          
                currentSum -= nums[start];
                window.erase(nums[start]);
                ++start;
            }
        }

        return maxSum;
    }
};
