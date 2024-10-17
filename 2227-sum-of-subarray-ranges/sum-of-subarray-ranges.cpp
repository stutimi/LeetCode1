class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long totalRangeSum = 0;
        vector<int> nextSmaller(n), prevSmaller(n), nextLarger(n), prevLarger(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            nextSmaller[stk.top()] = n; 
            stk.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            prevSmaller[stk.top()] = -1; 
            stk.pop();
        }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty()) stk.pop();
        }

        // Find next larger elements
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                nextLarger[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            nextLarger[stk.top()] = n; 
            stk.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                prevLarger[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            prevLarger[stk.top()] = -1; 
            stk.pop();
        }
        for (int i = 0; i < n; ++i) {
            long long maxContribution = (long long)(i - prevLarger[i]) * (nextLarger[i] - i) * nums[i];
            long long minContribution = (long long)(i - prevSmaller[i]) * (nextSmaller[i] - i) * nums[i];
            totalRangeSum += maxContribution - minContribution;
        }

        return totalRangeSum;
    }
};
