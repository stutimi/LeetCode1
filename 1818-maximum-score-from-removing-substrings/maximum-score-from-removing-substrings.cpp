class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper function to remove a pattern and return the points gained
        auto removePattern = [](std::string& str, char first, char second, int points) {
            std::stack<char> st;
            int score = 0;
            for (char c : str) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    score += points;
                } else {
                    st.push(c);
                }
            }
            // Build the remaining string after removal
            std::string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            std::reverse(remaining.begin(), remaining.end());
            return std::make_pair(remaining, score);
        };
        
        int totalScore = 0;
        
        if (x > y) {
            // Remove "ab" first
            auto result = removePattern(s, 'a', 'b', x);
            s = result.first;
            totalScore += result.second;
            
            // Then remove "ba"
            result = removePattern(s, 'b', 'a', y);
            totalScore += result.second;
        } else {
            // Remove "ba" first
            auto result = removePattern(s, 'b', 'a', y);
            s = result.first;
            totalScore += result.second;
            
            // Then remove "ab"
            result = removePattern(s, 'a', 'b', x);
            totalScore += result.second;
        }
        
        return totalScore;
    }
};