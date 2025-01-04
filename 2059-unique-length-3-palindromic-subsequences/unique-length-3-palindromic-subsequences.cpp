class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int length = s.size();
        int result = 0;
        unordered_map<char, int> freq_map;
        for (char c : s) {
            freq_map[c]++;
        }
        for (auto& entry : freq_map) {
            char char_to_check = entry.first;
            int left = 0, right = length - 1;
            while (s[left] != char_to_check) {
                left++;
            }
            while (s[right] != char_to_check) {
                right--;
            }
            unordered_set<char> middle_chars;
            for (int i = left + 1; i < right; i++) {
                middle_chars.insert(s[i]);
            }

            result += middle_chars.size();
        }

        return result;
    }
};
