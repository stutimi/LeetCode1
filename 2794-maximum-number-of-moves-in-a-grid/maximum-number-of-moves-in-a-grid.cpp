class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int maxMoves = 0;
        for (int col = 0; col < n - 1; ++col) {
            for (int row = 0; row < m; ++row) {
                if (dp[row][col] == col) {
                    for (int d = -1; d <= 1; ++d) {
                        int newRow = row + d, newCol = col + 1;
                        if (newRow >= 0 && newRow < m && grid[newRow][newCol] > grid[row][col]) {
                            dp[newRow][newCol] = max(dp[newRow][newCol], dp[row][col] + 1);
                            maxMoves = max(maxMoves, dp[newRow][newCol]);
                        }
                    }
                }
            }
        }
        
        return maxMoves;
    }
};
