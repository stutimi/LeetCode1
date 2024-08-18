class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1; 
        
        int i2 = 0, i3 = 0, i5 = 0;
        
        for (int i = 1; i < n; i++) {
            int nextUgly = min({2 * dp[i2], 3 * dp[i3], 5 * dp[i5]});
            dp[i] = nextUgly;
            if (nextUgly == 2 * dp[i2]) i2++;
            if (nextUgly == 3 * dp[i3]) i3++;
            if (nextUgly == 5 * dp[i5]) i5++;
        }
        
        return dp[n-1]; 
    }
};
