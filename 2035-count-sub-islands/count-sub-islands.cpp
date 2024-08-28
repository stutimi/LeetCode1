class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &isSubIsland) {
        int m = grid1.size(), n = grid2[0].size();
        
        // Check bounds
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0) {
            return;
        }
        
        // If grid2 has land but grid1 does not, then it's not a sub-island
        if (grid1[i][j] == 0) {
            isSubIsland = false;
        }
        
        // Mark the current cell in grid2 as visited by setting it to 0
        grid2[i][j] = 0;
        
        // Explore all 4 directions
        dfs(grid1, grid2, i + 1, j, isSubIsland);
        dfs(grid1, grid2, i - 1, j, isSubIsland);
        dfs(grid1, grid2, i, j + 1, isSubIsland);
        dfs(grid1, grid2, i, j - 1, isSubIsland);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid2[0].size();
        int subIslandCount = 0;
        
        // Traverse grid2
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find a part of an island in grid2
                if (grid2[i][j] == 1) {
                    bool isSubIsland = true;
                    // Perform DFS to check if it's a sub-island
                    dfs(grid1, grid2, i, j, isSubIsland);
                    // If all parts of the island in grid2 correspond to parts in grid1, it's a sub-island
                    if (isSubIsland) {
                        ++subIslandCount;
                    }
                }
            }
        }
        
        return subIslandCount;
    }
};
