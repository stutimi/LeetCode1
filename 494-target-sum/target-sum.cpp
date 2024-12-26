class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum < abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }
        int s1 = (sum + target) / 2;
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = s1; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[s1];
    }
};
