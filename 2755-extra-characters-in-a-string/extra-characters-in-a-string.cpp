class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        // Create a DP array where dp[i] is the minimum extra chars for substring s[0...i]
        vector<int> dp(n + 1, n);  // Initialize with a large value
        dp[0] = 0;  // No extra chars for empty string
        
        // Insert all words into a set for quick lookup
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        for (int i = 1; i <= n; ++i) {
            // Case 1: Treat the ith character as extra (in case we don't find a matching word)
            dp[i] = dp[i - 1] + 1; 
            
            // Case 2: Try to match substrings ending at i
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);  // Substring from j to i-1
                if (dict.count(sub)) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        
        return dp[n];
    }
};
