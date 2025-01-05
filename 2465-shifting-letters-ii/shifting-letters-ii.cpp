class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            int shift_value = (direction == 1) ? 1 : -1;
            diff[start] += shift_value;
            diff[end + 1] -= shift_value;
        }
        vector<int> cumulative_shift(n, 0);
        int current_shift = 0;
        for (int i = 0; i < n; ++i) {
            current_shift += diff[i];
            cumulative_shift[i] = current_shift;
        }
        for (int i = 0; i < n; ++i) {
            int original_pos = s[i] - 'a';
            int new_pos = (original_pos + cumulative_shift[i]) % 26;
            if (new_pos < 0) new_pos += 26; 
            s[i] = 'a' + new_pos;
        }
        
        return s;
    }
};
