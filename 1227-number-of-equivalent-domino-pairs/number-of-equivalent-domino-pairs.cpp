class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<int,int>freq;
        int cnt = 0;
        for(const auto& d : dominoes){
            int a = min(d[0],d[1]);
            int b = max(d[0],d[1]);
            int key = a*10 + b;
            cnt += freq[key];
            freq[key]++;
        }
        return cnt;
    }
};