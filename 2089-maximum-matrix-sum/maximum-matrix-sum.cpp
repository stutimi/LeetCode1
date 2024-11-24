class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int neg_cnt = 0;
        int s_e = INT_MAX;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++ ){
                ans  += abs(matrix[i][j]);
                s_e = min(s_e, abs(matrix[i][j]));
                if(matrix[i][j]<0) neg_cnt++;
            }
        }
        if(neg_cnt %2 == 0) return ans;
        return ans - (s_e*2);
    }
};