class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        for (const auto& index : indices) {
            rowCount[index[0]]++;
            colCount[index[1]]++;
        }
        
        int oddCells = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((rowCount[i] + colCount[j]) % 2 != 0) {
                    oddCells++;
                }
            }
        }
        
        return oddCells;

    }
};