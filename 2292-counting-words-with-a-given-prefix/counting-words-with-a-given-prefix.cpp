class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0; 
        for (auto word : words) {
            bool isPrefix = true; 
            if (word.size() < pref.size()) {
                continue; 
            }
            for (int i = 0; i < pref.size(); ++i) {
                if (word[i] != pref[i]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                count++;
            }
        }
        return count;
    }
};
