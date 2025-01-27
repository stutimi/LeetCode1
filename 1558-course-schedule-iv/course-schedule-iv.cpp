class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        vector<vector<int>> graph(n);
        for(auto pre : prerequisites){
            connected[pre[0]][pre[1]] = true;
            graph[pre[0]].push_back(pre[1]);
        }
        for(int i = 0; i < n; i++){
            connected[i][i] = true;
        }
        for(int start = 0; start < n; start++){
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(start);
            visited[start] = true;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                
                for(int nei : graph[cur]){
                    if(!visited[nei]){
                        connected[start][nei] = true;
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            ans[i] = connected[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};
