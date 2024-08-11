class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || visited[x][y])
            return;
        
        visited[x][y] = 1;
        
        dfs(grid, x + 1, y, visited);
        dfs(grid, x - 1, y, visited);
        dfs(grid, x, y + 1, visited);
        dfs(grid, x, y - 1, visited);
    }
    bool isConnected(vector<vector<int>>& grid) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int islands = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    if (islands > 1) return false;  
                    dfs(grid, i, j, visited);
                }
            }
        }
        
        return islands == 1;  
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (!isConnected(grid))
            return 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  
                    if (!isConnected(grid))  
                        return 1;
                    grid[i][j] = 1;  
                }
            }
        }
        return 2;
    }
};
