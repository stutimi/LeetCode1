class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstrings;
        return backtrack(s, 0, uniqueSubstrings);
    }
    
private:
    int backtrack(const string &s, int start, unordered_set<string> &uniqueSubstrings) {
        if (start == s.length()) {
            return uniqueSubstrings.size();
        }
        int maxCount = 0;
        for (int end = start + 1; end <= s.length(); ++end) {
            string substring = s.substr(start, end - start);
            if (uniqueSubstrings.find(substring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(substring); 
                maxCount = max(maxCount, backtrack(s, end, uniqueSubstrings));
                uniqueSubstrings.erase(substring);
            }
        }
        
        return maxCount;
    }
};
