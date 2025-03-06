class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        int repeated = 0, expectedSum = 0, actualSum = 0;
        expectedSum = (n * n * (n * n + 1)) / 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                if (seen.count(num) > 0) {
                    repeated = num;
                }
                seen.insert(num);
                actualSum += num;
            }
        }
        
        int missing = expectedSum - actualSum + repeated;
        
        return { repeated, missing };
    }
};