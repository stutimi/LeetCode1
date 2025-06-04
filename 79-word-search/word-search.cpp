class Solution {
public:
    int rows, cols;
    string target;
    
    bool dfs(vector<vector<char>>& board, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == target.size()) return true;
        if (i < 0 || j < 0 || i >= rows || j >= cols) return false;
        if (visited[i][j] || board[i][j] != target[index]) return false;

        visited[i][j] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int d = 0; d < 4; ++d) {
            int new_i = i + dx[d];
            int new_j = j + dy[d];
            if (dfs(board, new_i, new_j, index + 1, visited))
                return true;
        }

        visited[i][j] = false; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        target = word;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, i, j, 0, visited))
                    return true;
            }
        }
        return false;
    }
};
