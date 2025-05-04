class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        int freq[100] = {0};

        for (auto& d : dominoes) {
            int a = d[0];
            int b = d[1];
            int key;

            if (a < b)
                key = a * 10 + b;
            else
                key = b * 10 + a;

            count += freq[key];  
            freq[key]++;         
        }

        return count;
    }
};
