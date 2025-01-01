class Solution {
public:
    int maxScore(string s) {
        int cnt = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                right++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                left++;
            } else if (s[i] == '1') {
                right--;
            }
            int sc = left + right;
            cnt = max(cnt, sc);
        }
        return cnt;
    }
};
