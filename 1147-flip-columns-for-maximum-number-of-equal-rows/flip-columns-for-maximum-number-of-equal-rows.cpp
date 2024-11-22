class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> patternCount;
    int maxRows = 0;
    
    for (const auto& row : matrix) {
        string normalized, flipped;
        for (int cell : row) {
            // Normalize the row
            normalized += (cell == row[0] ? '0' : '1');
            // Flip the row
            flipped += (cell == row[0] ? '1' : '0');
        }
        // Increment count for normalized and flipped rows
        patternCount[normalized]++;
        maxRows = max(maxRows, patternCount[normalized]);
    }
    
    return maxRows;
}

};