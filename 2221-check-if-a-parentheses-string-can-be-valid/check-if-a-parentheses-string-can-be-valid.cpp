class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; 
        
        int open = 0, balance = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') open++;
                else open--;
            } else {
                open++;
            }
            if (open < 0) return false;
        }

        open = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') open++;
                else open--;
            } else {
                open++;
            }
            if (open < 0) return false;
        }

        return true;
    }
};
