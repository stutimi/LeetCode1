class Solution {
public:
    bool checkRecord(string s) {
        int ca = 0; 
        int cl = 0;
        for (char c : s) {
            if (c == 'A') {
                ca++;
                if (ca >= 2) return false;
                cl = 0; 
            } else if (c == 'L') {
                cl++;
                if (cl >= 3) return false;
            } else {
                cl = 0; 
            }
        }
        return true;
    }
};
