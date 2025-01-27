class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, count = 0, extra = 0;
        for (int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            if (mp.size() == k + 1) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                extra = 0;
                i++; }
            while (mp[nums[i]] > 1) {
                mp[nums[i]]--;
                extra++;
                i++; }
            if (mp.size() == k) {
                count += (1 + extra);  }
        }
        return count; }
};
