class Solution {
public:

set<string> result;
map<int,int>flag;
string S;
    int numTilePossibilities(string tiles) {
        solve(tiles);
        return result.size();
    }
    void solve(string tiles){
        for(int i = 0; i<tiles.size(); i++){
            if(flag[i]!=1){
                S.push_back(tiles[i]);
                flag[i]=1;
                result.insert(S);
                solve(tiles);
                flag[i]=0;
                S.pop_back();
            }
        }
    }
};