class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityMatch(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            parityMatch[i] = (nums[i] % 2 == nums[i + 1] % 2) ? 1 : 0;
        }
        vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + parityMatch[i - 1];
        }
        vector<bool> result;
        for (auto& query : queries) {
            int from = query[0];
            int to = query[1];
            if (to == from) {
                result.push_back(true);
            } else {
                int sameParityCount = prefixSum[to] - prefixSum[from];
                result.push_back(sameParityCount == 0);
            }
        }
        return result;
    }
};
