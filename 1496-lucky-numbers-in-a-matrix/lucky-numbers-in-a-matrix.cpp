class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
          vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            int minElement = matrix[i][0];
            int colIndex = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    colIndex = j;
                }
            }
            bool isLucky = true;
            for (int k = 0; k < m; ++k) {
                if (matrix[k][colIndex] > minElement) {
                    isLucky = false;
                    break;
                }
            }
            if (isLucky) {
                result.push_back(minElement);
            }
        }
        return result;
    }
};