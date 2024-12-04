class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        if (n > m) return false;
        int firstStr = 0, secondStr = 0;
        while (firstStr < m && secondStr < n) {
            char next_char = char((str1[firstStr] - 'a' + 1) % 26 + 'a');
            if (str1[firstStr] == str2[secondStr] || next_char == str2[secondStr]) {
                secondStr++; 
            }
            firstStr++;  
        }
        return secondStr == n;
    }
};
