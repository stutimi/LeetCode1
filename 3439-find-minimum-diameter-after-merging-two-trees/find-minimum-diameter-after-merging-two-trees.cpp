class Solution {
public:

    int border, diameter;

    void dfs(vector< vector<int> >& graph, int v, int p, int d){
        
        if(d > diameter){
            border = v;
            diameter = d;
        }

        for(auto&u: graph[v]){
            if(u == p) continue;
            dfs(graph, u, v, d + 1);
        }
    }

    int tree_diameter(vector< vector<int> >& graph){

        diameter = -1;
        dfs(graph, 0, -1, 0);
        diameter = -1;
        dfs(graph, border, -1, 0);

        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

            int n = edges1.size() + 1;
            int m = edges2.size() + 1;

            vector< vector<int> > g1(n);
            vector< vector<int> > g2(m);

            for(auto&e: edges1){
                g1[e[0]].push_back(e[1]);
                g1[e[1]].push_back(e[0]);
            }

            for(auto&e: edges2){
                g2[e[0]].push_back(e[1]);
                g2[e[1]].push_back(e[0]);
            }

            int d1 = tree_diameter(g1);
            int d2 = tree_diameter(g2);
            if(d1 < d2) swap(d1, d2);

            return max(d1, (int) (ceil(d1/2.0) + ceil(d2/2.0) + 1));


    }
};