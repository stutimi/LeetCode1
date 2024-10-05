class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;

        // Frequency arrays for s1 and s2's current window
        vector<int> s1Freq(26, 0), windowFreq(26, 0);
        
        // Fill s1Freq with frequencies of characters in s1
        for (int i = 0; i < len1; ++i) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;  // Initial window in s2
        }

        // Check initial window
        if (s1Freq == windowFreq) return true;

        // Start sliding the window over s2
        for (int i = len1; i < len2; ++i) {
            windowFreq[s2[i] - 'a']++;   // Add new character to window
            windowFreq[s2[i - len1] - 'a']--;  // Remove old character from window

            // Check if frequencies match
            if (s1Freq == windowFreq) return true;
        }

        return false;
    }
};
