class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<bool> marked(n, false);
        vector<pair<int, int>> elements;
        for (int i = 0; i < n; ++i) {
            elements.push_back({nums[i], i});
        }
        sort(elements.begin(), elements.end());
        for (auto [value, index] : elements) {
            if (!marked[index]) {
                score += value;
                marked[index] = true;
                if (index > 0) marked[index - 1] = true;
                if (index < n - 1) marked[index + 1] = true;
            }
        }
        return score;
    }
};