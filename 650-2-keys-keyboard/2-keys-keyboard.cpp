class Solution {
public:
    int minSteps(int n) {
        int result = 0;
        for (int d = 2; d <= n; ++d) {
            while (n % d == 0) {
                result += d;
                n /= d;
            }
        }
        return result;
    }
};
