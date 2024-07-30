class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int aCount = 0, bCount = 0;
        int minDeletions = n; // Start with max deletions as the length of the string

        // Count total number of 'a's in the string
        for (char c : s) {
            if (c == 'a') aCount++;
        }

        int currentACount = 0;
        // Traverse the string and calculate the minimum deletions
        for (char c : s) {
            if (c == 'a') {
                currentACount++;
            } else {
                bCount++;
            }
            // Calculate the number of deletions required if we delete all 'a's after the current point and all 'b's before the current point
            minDeletions = min(minDeletions, bCount + (aCount - currentACount));
        }

        // If the entire string is either all 'a' or all 'b', minDeletions should be 0
        minDeletions = min(minDeletions, aCount);
        minDeletions = min(minDeletions, bCount);

        return minDeletions;

    }
};