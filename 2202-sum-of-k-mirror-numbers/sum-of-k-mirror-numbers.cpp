#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int found = 0;
        int len = 1;

        while (found < n) {
            for (int half = pow(10, len - 1); half < pow(10, len) && found < n; ++half) {
                string s = to_string(half);
                string rev(s.rbegin() + 1, s.rend());
                long long num = stoll(s + rev);
                if (isKPalindrome(num, k)) {
                    sum += num;
                    found++;
                }
            }

            for (int half = pow(10, len - 1); half < pow(10, len) && found < n; ++half) {
                string s = to_string(half);
                string rev(s.rbegin(), s.rend());
                long long num = stoll(s + rev);
                if (isKPalindrome(num, k)) {
                    sum += num;
                    found++;
                }
            }

            len++;
        }

        return sum;
    }

private:
    bool isKPalindrome(long long num, int k) {
        string baseK = "";
        while (num > 0) {
            baseK += char('0' + num % k);
            num /= k;
        }
        int l = 0, r = baseK.size() - 1;
        while (l < r) {
            if (baseK[l++] != baseK[r--]) return false;
        }
        return true;
    }
};
