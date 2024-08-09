class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<int> count(10, 0);
        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }
        int sum1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int sum2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int sum3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];
        if (sum1 != 15 || sum2 != 15 || sum3 != 15) return false;
        
        int sum4 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int sum5 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int sum6 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
        if (sum4 != 15 || sum5 != 15 || sum6 != 15) return false;
        
        int sum7 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int sum8 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if (sum7 != 15 || sum8 != 15) return false;
        
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
