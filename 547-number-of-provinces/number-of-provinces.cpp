class Solution {
private:
    void bfs(int node, vector<int> adjList[], vector<bool> &visited) {
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adjList[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Convert adjacency matrix to adjacency list
        vector<int> adjList[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                bfs(i, adjList, visited);
                // Alternatively: dfs(i, adjList, visited);
            }
        }

        return provinces;
    }
};
