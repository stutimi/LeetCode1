class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int count = 0, currentSum = 0;

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.count(i)) continue; 
            if (currentSum + i > maxSum) break; 
            currentSum += i;
            count++;
        }

        return count;
    }
};
