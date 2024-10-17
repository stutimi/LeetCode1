class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        long long res = 0, mod = 1e9 + 7;
        vector<int> prevLess(n, -1), nextLess(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                nextLess[stk.top()] = i;
                stk.pop();
            }
            prevLess[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;
            res = (res + arr[i] * left * right) % mod;
        }

        return res;
    }
};
