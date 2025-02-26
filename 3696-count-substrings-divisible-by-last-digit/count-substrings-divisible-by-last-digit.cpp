class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long result = 0;
        vector<vector<int>> dp(10, vector<int>(10, 0)); 
        for (int i = 0; i < n; i++) {
            vector<vector<int>> new_dp(10, vector<int>(10, 0));
            int x = s[i] - '0'; 
            for (int d = 1; d <= 9; d++) { 
                new_dp[d][x % d] += 1; 
                for (int r = 0; r < d; r++) {
                    new_dp[d][(r * 10 + x) % d] += dp[d][r];
                }
            }
            dp = new_dp;
            result += dp[x][0];
        }
        return result;
    }
};

