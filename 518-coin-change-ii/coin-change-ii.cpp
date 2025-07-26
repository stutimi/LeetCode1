class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        // If result exceeds int range, cast carefully
        if (dp[amount] > INT_MAX) return -1; // optional safety check
        return dp[amount];
    }
};
