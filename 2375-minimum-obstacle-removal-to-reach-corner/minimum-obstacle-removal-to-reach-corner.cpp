class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        dist[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.emplace_back(0, 0);
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) {
                            dq.emplace_front(nx, ny); 
                        } else {
                            dq.emplace_back(nx, ny); 
                        }
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};