class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> line_sweep;
        for(auto& event: events){
            int start = event[0];
            int end = event[1];
            int val = event[2];
            line_sweep.push_back({start,1,val});
            line_sweep.push_back({end+1,-1,val});
        }
        sort(line_sweep.begin(),line_sweep.end());
        int max_val=0;
        int max_seen=0;
        for(auto& event: line_sweep){
            int point = event[0];
            int status = event[1];
            int val = event[2];
            if(status==1)
                max_val = max(max_val,max_seen+val);
            if(status==-1)
                max_seen = max(max_seen,val);
        }
        return max_val;
    }
};