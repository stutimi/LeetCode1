class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> parent(4 * n * n);
        for (int i = 0; i < 4 * n * n; ++i) {
            parent[i] = i;
        }
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = 4 * (i * n + j); 
                if (grid[i][j] == '/') {
                    unite(index + 0, index + 3); 
                    unite(index + 1, index + 2); 
                } else if (grid[i][j] == '\\') {
                    unite(index + 0, index + 1); 
                    unite(index + 2, index + 3); 
                } else { // ' '
                    unite(index + 0, index + 1);
                    unite(index + 1, index + 2);
                    unite(index + 2, index + 3);
                }
                if (i > 0) { 
                    unite(index + 0, 4 * ((i - 1) * n + j) + 2);
                }
                if (j > 0) { 
                    unite(index + 3, 4 * (i * n + (j - 1)) + 1);
                }
            }
        }
        int regions = 0;
        for (int i = 0; i < 4 * n * n; ++i) {
            if (find(i) == i) {
                ++regions;
            }
        }
        
        return regions;
    }
};
