class Solution {
    void fill(vector<vector<char>>& res,int count,int x,int y){
        while(count){
            res[x][y]='#';
            x--;
            count--;
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();

        vector<vector<char>> res(n,vector<char>(m,'.'));

        for(int i=0;i<m;++i){
            int count=0;
            for(int j=0;j<n;++j){
                if(box[i][j]=='#')  count++;
                else if(box[i][j]=='*'){
                    res[j][m-i-1]='*';
                    fill(res,count,j-1,m-i-1);
                    count=0;
                }
            }
            if(count>0)
                fill(res,count,n-1,m-i-1);
        }
        return res;
    }
};