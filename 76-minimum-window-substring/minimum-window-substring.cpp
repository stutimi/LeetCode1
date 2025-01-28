class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int hash[256] = {0};
        for (char c : t) {
            hash[c]++;}
        int l = 0, r = 0, cnt = 0; 
        int minLen = INT_MAX, strInd = -1;
        int m = t.size(), n = s.size();
        while (r < n) {
            if (hash[s[r]] > 0) {  cnt++;}
            hash[s[r]]--; r++;
            while (cnt == m) {
                if (r - l < minLen) { 
                    minLen = r - l;
                    strInd = l;  }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;}
                l++;  } }
        return strInd == -1 ? "" : s.substr(strInd, minLen); }};
