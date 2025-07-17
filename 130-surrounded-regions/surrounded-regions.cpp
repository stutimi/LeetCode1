#include <vector>
using namespace std;

class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(int row, int col, vector<vector<bool>> &vis,
             vector<vector<char>> &mat, int n, int m) {
        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (isValid(nRow, nCol, n, m) &&
                mat[nRow][nCol] == 'O' &&
                !vis[nRow][nCol]) {
                dfs(nRow, nCol, vis, mat, n, m);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse boundary rows
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, vis, board, n, m);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, vis, board, n, m);
        }

        // Traverse boundary columns
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, n, m);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board, n, m);
        }

        // Replace unvisited 'O' with 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
