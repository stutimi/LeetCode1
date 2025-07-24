class Solution {
public:
    vector<vector<int>> tree;
    vector<int> sum, in, out;
    int time = 0;

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.resize(n);
        sum.resize(n);
        in.resize(n);
        out.resize(n);

        // Build tree
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // Preprocess with DFS
        dfs(0, -1, nums);

        int totalXOR = sum[0];
        int ans = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isAncestor(i, j)) {
                    int x = totalXOR ^ sum[i];
                    int y = sum[i] ^ sum[j];
                    int z = sum[j];
                    ans = min(ans, getScore(x, y, z));
                } else if (isAncestor(j, i)) {
                    int x = totalXOR ^ sum[j];
                    int y = sum[j] ^ sum[i];
                    int z = sum[i];
                    ans = min(ans, getScore(x, y, z));
                } else {
                    int x = totalXOR ^ sum[i] ^ sum[j];
                    int y = sum[i];
                    int z = sum[j];
                    ans = min(ans, getScore(x, y, z));
                }
            }
        }

        return ans;
    }

    void dfs(int node, int parent, vector<int>& nums) {
        in[node] = time++;
        sum[node] = nums[node];
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, node, nums);
                sum[node] ^= sum[child];
            }
        }
        out[node] = time;
    }

    bool isAncestor(int u, int v) {
        return in[u] < in[v] && out[v] <= out[u];
    }

    int getScore(int a, int b, int c) {
        return max({a, b, c}) - min({a, b, c});
    }
};

