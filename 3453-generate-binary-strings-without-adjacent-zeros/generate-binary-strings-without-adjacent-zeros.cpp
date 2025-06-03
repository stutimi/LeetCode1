class Solution {
public:
    vector<string> ans;

    void func(int n, string s) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }
        if (s.empty() || s.back() == '1') {
            func(n - 1, s + '0');
            func(n - 1, s + '1');
        } else {
            func(n - 1, s + '1');
        }
    }

    vector<string> validStrings(int n) {
        ans.clear();          
        func(n, "");           
        return ans;
    }
};
