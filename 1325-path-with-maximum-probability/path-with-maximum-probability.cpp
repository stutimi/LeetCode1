class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(b, prob);
            graph[b].emplace_back(u, prob);
        }
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);  
        maxProb[start] = 1.0;  
        pq.emplace(1.0, start);
        
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            if (node == end) {
                return prob;
            }
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.emplace(newProb, neighbor);
                }
            }
        }
        
        return 0.0;  
    }
};
