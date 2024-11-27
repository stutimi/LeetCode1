class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n); 
        for (int i = 0; i < n - 1; i++) {
            graph[i].emplace_back(i + 1, 1); 
        }

        vector<int> answer;

        auto dijkstra = [&](int start, int end) -> int {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

            dist[start] = 0;
            pq.emplace(0, start);

            while (!pq.empty()) {
                auto [currentDist, currentNode] = pq.top();
                pq.pop();

                if (currentDist > dist[currentNode]) continue;

                for (auto& [neighbor, weight] : graph[currentNode]) {
                    int newDist = currentDist + weight;
                    if (newDist < dist[neighbor]) {
                        dist[neighbor] = newDist;
                        pq.emplace(newDist, neighbor);
                    }
                }
            }

            return dist[end];
        };

        for (auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].emplace_back(v, 1); 
            answer.push_back(dijkstra(0, n - 1)); 
        }

        return answer; 
    }
};