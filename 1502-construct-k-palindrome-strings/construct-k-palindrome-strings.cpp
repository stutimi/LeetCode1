class Solution {
public:
    bool canConstruct(string s, int k) {
       if(s.size()<k) return false;
       map<int,int>m;
       int no = 0;
       for(auto a:s ) m[a]++;
       for(auto a:m) if(a.second%2==1) no++;
       return no<=k; 
    }
};