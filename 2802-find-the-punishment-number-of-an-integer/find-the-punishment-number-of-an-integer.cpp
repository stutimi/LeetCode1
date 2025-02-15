class Solution {
public:
    bool isValidPartition(string sq, int target, int start = 0, int sum = 0) {
        if (start == sq.length()) return sum == target;
        int num = 0;
        for (int i = start; i < sq.length(); i++) {
            num = num * 10 + (sq[i] - '0');
            if (num + sum <= target && isValidPartition(sq, target, i + 1, sum + num)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            int squared = i * i;
            string sqStr = to_string(squared);
            if (isValidPartition(sqStr, i)) {
                total += squared;
            }
        }
        return total;
    }
};
