class Solution {
    vector<int> DFS(vector<vector<int>>& indegree, vector<vector<int>>& outdegree, int pp, 
        vector<bool>& visited, int len, int& res, int last, vector<vector<int>>& cached) {
        if (outdegree[pp].size() == 1) {
            cached[pp] = {1, 1, 0};
            return {1, 1, 0};
        }
        int no_cicle1 = 0;
        int cicle1_num = -1;
        int no_cicle2 = 0;
        int has_circle = 0;
        int must_path = 0;
        int must = -1;
        for (int i = 1; i < outdegree[pp].size(); i++) {
            int next_pp = outdegree[pp][i];
            vector<int> ret;
            if (cached[next_pp][0] == -1) {
                for (int k = 1; k < outdegree[next_pp].size(); k++) {
                    if (outdegree[next_pp][k] == pp) {
                        must = next_pp;
                        break;
                    }
                }
                if (visited[next_pp]) {
                   
                    if (last != next_pp) {
                        has_circle = 1;
                        res = max(res, len);
                    }
                    continue;
                }
                visited[outdegree[pp][i]] = true;
                ret = DFS(indegree, outdegree, outdegree[pp][i], visited, len+1, res, pp, cached);
            }
            else {
                ret = cached[next_pp];
            }
            if (must == next_pp) {
                must_path = max(ret[0], ret[1]);
            }
            if (ret[0] > no_cicle1) {
                no_cicle2 = no_cicle1;
                no_cicle1 = ret[0];
                cicle1_num = next_pp;
            }
            else if (ret[0] > no_cicle2) no_cicle2 = ret[0];
            has_circle |= ret[2];
        }
        int mx = no_cicle1 > 0 ? no_cicle1+1 : 1;
        int mn = cicle1_num == must ? no_cicle2 : must_path > 0 ? must_path : no_cicle2;

        cached[pp] = {mx, mn, has_circle};
        return cached[pp];
    }
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> indegree(n, vector<int>(1, 0));
        vector<vector<int>> outdegree(n, vector<int>(1, 0));
        vector<vector<int>> cached(n, vector<int>(3, -1));
        for (int i = 0; i < n; i++) {
            indegree[i][0]++;
            indegree[i].push_back(favorite[i]);
            outdegree[favorite[i]][0]++;
            outdegree[favorite[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        int res = 0;
        int total = 0;
     
        for (int i = 0; i < n; i++) {
            if (visited[i] || outdegree[i][0] == 0) continue;
            
            visited[i] = true;
            auto ret = DFS(indegree, outdegree, i, visited, 1, res, -1, cached);
            if (ret[2] == 1) continue;
   
            if (indegree[i][0] == 0) {
                total += ret[0] + ret[1];
            }
         
            for (int j = 1; j < outdegree[i].size(); j++) {
                int nx = outdegree[i][j];
                bool b = false;
                for (int k = 1; k < outdegree[nx].size(); k++) {
                    if (outdegree[nx][k] == i) {
                        total += ret[0] + ret[1];

                        b = true;
                        break;
                    }
                }
                if (b) break;
            }
            
        }
        res = max(res, total);
        return res;
    }
};