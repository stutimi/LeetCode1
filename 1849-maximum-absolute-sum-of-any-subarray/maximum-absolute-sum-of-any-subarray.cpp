class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        return std::max(
            std::abs(minSS(nums)),
            std::abs(maxSS(nums))
        );
    }
private:
    int maxSS(std::vector<int>& nums) {
        int t = 0, maxSum = INT_MIN;
        for (int num : nums) {
            t += num;
            maxSum = std::max(maxSum, t);
            if (t < 0) t = 0;
        }
        return maxSum;
    }
    int minSS(std::vector<int>& nums) {
        int t = 0, minSum = INT_MAX;
        for (int num : nums) {
            t += num;
            minSum = std::min(minSum, t);
            if (t > 0) t = 0;
        }
        return minSum;
    }
};
