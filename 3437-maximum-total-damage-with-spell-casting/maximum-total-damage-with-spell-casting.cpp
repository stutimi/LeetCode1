#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> total;
        for (int x : power)
            total[x] += x;  

        vector<long long> vals, sums;
        for (auto &p : total) {
            vals.push_back(p.first);
            sums.push_back(p.second);
        }

        int n = vals.size();
        vector<long long> dp(n);
        dp[0] = sums[0];

        for (int i = 1; i < n; ++i) {
          
            int j = upper_bound(vals.begin(), vals.begin() + i, vals[i] - 3) - vals.begin() - 1;
            long long include = sums[i] + (j >= 0 ? dp[j] : 0);
            dp[i] = max(dp[i - 1], include);
        }

        return dp[n - 1];
    }
};
