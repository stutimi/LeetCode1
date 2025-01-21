class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        int lateStreak = 0;

        for (char c : s) {
            if (c == 'A') {
                absentCount++;
                if (absentCount >= 2) return false;
            }
            if (c == 'L') {
                lateStreak++;
                if (lateStreak >= 3) return false;
            } else {
                lateStreak = 0;
            }
        }

        return true;
    }
};
;