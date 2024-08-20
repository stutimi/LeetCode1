class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);
        
        
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                int maxStones = 0;
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    maxStones = max(maxStones, suffixSum[i] - dp[i + x][max(m, x)]);
                }
                dp[i][m] = maxStones;
            }
        }
        
        return dp[0][1];
    }
};
