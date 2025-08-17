class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0) return 1;
        if(K-1+W <= N) return 1;
        if(N < K) return 0;
        vector<double> dp(N+1, 0);
        dp[0] = 1;
        double Wsum = 1; 
        double res = 0;
        for(int i = 1; i <= N; ++i){
            dp[i] = Wsum/W;
            if(i < K){
                Wsum += dp[i];
            }else{
                res += dp[i];
            }
            if(i-W >= 0) Wsum -= dp[i-W];
        }
        return res;
    }
};