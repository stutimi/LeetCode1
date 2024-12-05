class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        // Filter out '_' from both strings and compare the sequences
        string s1, s2;
        for (char c : start) if (c != '_') s1 += c;
        for (char c : target) if (c != '_') s2 += c;
        
        if (s1 != s2) return false;

        // Two pointers to check valid movements
        int i = 0, j = 0;
        while (i < n && j < n) {
            // Find next non-blank character in start and target
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If one pointer reaches the end before the other
            if (i == n || j == n) break;

            // Compare positions and validate movement rules
            if (start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false; // 'L' cannot move right
            if (start[i] == 'R' && i > j) return false; // 'R' cannot move left
            
            i++;
            j++;
        }

        return true;
    }
};
