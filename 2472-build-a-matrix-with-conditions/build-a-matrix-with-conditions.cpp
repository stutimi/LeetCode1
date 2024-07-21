class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> indegree(k + 1, 0);
    unordered_map<int, vector<int>> graph;

    for (auto& condition : conditions) {
        int u = condition[0], v = condition[1];
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= k; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (order.size() != k) {
        return {};
    }

    return order;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topologicalSort(k, rowConditions);
    vector<int> colOrder = topologicalSort(k, colConditions);

    if (rowOrder.empty() || colOrder.empty()) {
        return {};
    }

    unordered_map<int, int> rowIndex;
    unordered_map<int, int> colIndex;

    for (int i = 0; i < k; i++) {
        rowIndex[rowOrder[i]] = i;
        colIndex[colOrder[i]] = i;
    }

    vector<vector<int>> matrix(k, vector<int>(k, 0));
    for (int num = 1; num <= k; num++) {
        matrix[rowIndex[num]][colIndex[num]] = num;
    }

    return matrix;

    }
};