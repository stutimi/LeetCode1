class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto& d : dominoes) {
            if (d[0] > d[1]) swap(d[0], d[1]);
        }

         sort(dominoes.begin(), dominoes.end());
        int count = 0;
        int same = 1;

        for (int i = 1; i < dominoes.size(); ++i) {
            if (dominoes[i] == dominoes[i - 1]) {
                count += same;
                same++;
            } else {
                same = 1;
            }
        }

        return count;
    }
};
