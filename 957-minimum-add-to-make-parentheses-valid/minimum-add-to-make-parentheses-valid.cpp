class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;  // Tracks unmatched '('
        int right = 0; // Tracks unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                left++;  // We have an unmatched '('
            } else {
                if (left > 0) {
                    left--;  // Match the ')' with an unmatched '('
                } else {
                    right++; // We have an unmatched ')'
                }
            }
        }
        
        // The result is the sum of unmatched '(' and ')'
        return left + right;
    }
};
;