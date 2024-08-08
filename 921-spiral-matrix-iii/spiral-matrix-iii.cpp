class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total_cells = rows * cols;
        int r = rStart, c = cStart;
        int steps = 0;
        int direction = 0; 
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        
        result.push_back({r, c});
        while (result.size() < total_cells) {
            if (direction == 0 || direction == 2) steps++;
            for (int i = 0; i < steps; i++) {
                r += dr[direction];
                c += dc[direction];
                
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                }
            }
            direction = (direction + 1) % 4;
        }
        
        return result;
    }
};
