class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> heights(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Directions for moving in 4 possible directions: up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Initialize water cells with height 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    heights[i][j] = 0;
                }
            }
        }
        
        // BFS to fill the heights
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int current_height = heights[x][y];
            
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && heights[nx][ny] == -1) {
                    heights[nx][ny] = current_height + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return heights;
    }
};