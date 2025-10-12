#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        int maxCarry = m; // max possible carry
        vector<vector<vector<vector<ll>>>> dp(
            n + 1,
            vector<vector<vector<ll>>>(maxCarry + 2, vector<vector<ll>>(m + 1, vector<ll>(k + 1, -1)))
        );

        // Precompute powers and factorials
        vector<vector<ll>> powNum(n, vector<ll>(m + 1, 1));
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                powNum[i][j] = powNum[i][j - 1] * nums[i] % MOD;

        vector<ll> fact(m + 1, 1), invFact(m + 1, 1);
        for (int i = 1; i <= m; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[m] = modInverse(fact[m]);
        for (int i = m - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        function<ll(int, int, int, int)> dfs = [&](int pos, int carry, int used, int bits) -> ll {
            if (bits > k) return 0;
            if (pos == n) {
                if (carry == 0 && used == m && bits == k) return 1;
                if (used == m) {
                    int addBits = __builtin_popcountll(carry);
                    return (bits + addBits == k) ? 1 : 0;
                }
                return 0;
            }
            ll &res = dp[pos][carry][used][bits];
            if (res != -1) return res;
            res = 0;
            for (int cnt = 0; cnt <= m - used; cnt++) {
                int newCarry = (carry + cnt) >> 1;
                int newBits = bits + ((carry + cnt) & 1);
                ll ways = fact[m - used] * invFact[cnt] % MOD * invFact[m - used - cnt] % MOD;
                ll val = powNum[pos][cnt];
                ll add = dfs(pos + 1, newCarry, used + cnt, newBits);
                res = (res + add * val % MOD * ways) % MOD;
            }
            return res;
        };

        return (int)dfs(0, 0, 0, 0);
    }

    ll modPow(ll a, ll b) {
        ll res = 1;
        const int MOD = 1e9 + 7;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    ll modInverse(ll a) {
        return modPow(a, 1e9 + 7 - 2);
    }
};
