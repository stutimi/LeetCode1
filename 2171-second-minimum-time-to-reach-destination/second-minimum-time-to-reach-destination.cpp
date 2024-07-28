class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<vector<int>> seen(n);
        int least = -1;

        while (!pq.empty()) {
            
            auto [t, u] = pq.top();
            pq.pop();
            if (u == n - 1) {
                if (least == -1) {
                    least = t;
                }
                else if (least < t) {
                    return t;
                }
            }
            if ((t / change) % 2 == 1) {
                t = (t / change + 1) * change;
            }
            t += time;
            for (int v : graph[u]) {
                if (seen[v].empty() || (seen[v].size() == 1 && seen[v][0] != t)) {
                    seen[v].push_back(t);
                    pq.push({t, v});
                }
            }
        }
        return -1;
    }
};