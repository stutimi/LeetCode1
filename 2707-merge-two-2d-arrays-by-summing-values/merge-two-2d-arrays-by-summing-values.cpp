class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        
        for (auto& a : nums1) {
            mp[a[0]] = a[1];
        }
        
        for (auto& a : nums2) {
            if (mp.find(a[0]) != mp.end()) {
                mp[a[0]] += a[1];
            } else {
                mp[a[0]] = a[1];
            }
        }
        
        vector<vector<int>> ans;
        for (auto& [key, value] : mp) {
            ans.push_back({key, value});
        }
        
        return ans;
    }
};