class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        vector<int> left(3, -1);
        for (int right = 0; right < s.length(); ++right) {
            left[s[right] - 'a'] = right;
            result += *min_element(cbegin(left), cend(left)) + 1;
        }
        return result;
    }
};
