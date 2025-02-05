class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; 
        int n = s1.size();
        int first = -1, second = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2) return false;
                if (first == -1)
                    first = i;
                else second = i;
            }
        }
        if (count != 2) return false; 
        return (s1[first] == s2[second] && s1[second] == s2[first]);
    }
};
