class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        int maxLen = -1;
        for (int k = 1; k <= n; ++k) { 
            unordered_map<string, int> freqMap;
            for (int i = 0; i <= n - k; ++i) {
                string sub = s.substr(i, k);
                if (allSame(sub)) {
                    freqMap[sub]++;
                    if (freqMap[sub] >= 3) {
                        maxLen = max(maxLen, k);
                    }
                }
            }
        }
        return maxLen;
    }
private:
    bool allSame(const string& sub) {
        char c = sub[0];
        for (char ch : sub) {
            if (ch != c) return false;
        }
        return true;
    }
};
