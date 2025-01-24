class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (int neighbor : reverseGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
