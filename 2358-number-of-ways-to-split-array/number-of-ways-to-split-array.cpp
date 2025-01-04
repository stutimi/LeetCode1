class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for (auto num : nums) {
            totalSum += num;
        }
        int cnt = 0;
        long long csum = 0;
        for (int i = 0; i < n - 1; i++) {
            csum += nums[i];
            if (csum >= totalSum - csum) {
                cnt++;
            }
        }
        return cnt;
    }
};
