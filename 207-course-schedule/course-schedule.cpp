class Solution {
private:

    vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> inDegree(V, 0);
		for (int i = 0; i < V; i++) {
			for(auto it : adj[i]) {
			    inDegree[it]++;
			}
		}
        vector<int> ans;
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }
	    while(!q.empty()) {
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it : adj[node]) {
	            inDegree[it]--;
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
    }
    
public:
	bool canFinish(int N, vector<vector<int>> arr) {
        vector<int> adj[N];
        for(auto it : arr) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int> topo = topoSort(N, adj);
        if(topo.size() < N) return false;
        return true;
    }
};