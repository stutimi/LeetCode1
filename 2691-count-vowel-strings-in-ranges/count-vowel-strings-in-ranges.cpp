class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n, 0);
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        for (int i = 0; i < n; i++) {
            int count = 0;
            int len = words[i].size();
            if (isVowel(words[i][0]) && isVowel(words[i][len - 1])) {
                count = 1;
            }
            prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + count;
        }
        vector<int> result;
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            int countInRange = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
            result.push_back(countInRange);
        }
        return result;
    }
};
