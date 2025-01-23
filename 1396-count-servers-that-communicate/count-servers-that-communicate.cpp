class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int total = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);

        // Count the total servers and track the number of servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    total++;
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // Deduct isolated servers (those with count 1 in their row and column)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    total--;
                }
            }
        }

        return total;
    }
};
