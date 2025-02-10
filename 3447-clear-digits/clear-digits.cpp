class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(char c: s){
            if(c>='0' and c<='9') res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};