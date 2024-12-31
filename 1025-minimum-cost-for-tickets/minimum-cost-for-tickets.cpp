class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        vector<int> dp(N);
        dp[0] = min({costs[0], costs[1], costs[2]});
        for(int i = 1; i < N; i++){
            int idx7 = upper_bound(days.begin(), days.end(), days[i]-7)-days.begin()-1; 
            int idx30 = upper_bound(days.begin(), days.end(), days[i]-30)-days.begin()-1;
            dp[i] = min({dp[i-1] + costs[0],
                        ((idx7 >= 0 && days[i]-days[idx7]>=7)?dp[idx7]:0) + costs[1],
                        ((idx30 >= 0 && days[i]-days[idx30]>=30)?dp[idx30]:0) + costs[2]
                        });
        }
        return dp[N-1];
    }
};