class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string curr_state;
        for(int i=0;i<2;++i)
            for(int j=0;j<3;++j)
                curr_state.push_back(char('0'+board[i][j]));
        
        string target_state = "123450";
      
        queue<string> q;   
        q.push(curr_state);
        unordered_set<string> visited;
        visited.insert(curr_state);
        vector<vector<int>> dirs = {{1,3},{0,2,4},{1,5},
                                    {0,4},{1,3,5},{2,4}};
        int levels=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                string curr_state = q.front();
                q.pop();

                if(curr_state == target_state)  return levels;
   
                int zero_pos;
                for(int i=0;i<6;++i)
                    if(curr_state[i]=='0'){
                        zero_pos=i;
                        break;
                    }
                for(auto& dir: dirs[zero_pos]){
                    string new_state = curr_state;
                    swap(new_state[zero_pos],new_state[dir]);

                    if(!visited.count(new_state)){
                        visited.insert(new_state);
                        q.push(new_state);
                    }
                }
            }
            levels+=1;
        }
        return -1;
    }
};
