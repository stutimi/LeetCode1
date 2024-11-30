class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        int start = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outDegree[node] - inDegree[node] == 1) {
                start = node;
                break;
            }
        }

    
        vector<int> path;
        stack<int> stack;
        stack.push(start);

        while (!stack.empty()) {
            int node = stack.top();
            if (graph[node].empty()) {
                path.push_back(node);
                stack.pop();
            } else {
                int next = graph[node].back();
                graph[node].pop_back();
                stack.push(next);
            }
        }

        reverse(path.begin(), path.end());

        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; i++) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};
