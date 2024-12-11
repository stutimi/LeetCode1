class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> events;
        for (int num : nums) {
            events.push_back({num - k, 1}); 
            events.push_back({num + k + 1, -1}); 
        }
        sort(events.begin(), events.end());
        int maxBeauty = 0, currentOverlap = 0;
        for (auto& event : events) {
            currentOverlap += event.second;
            maxBeauty = max(maxBeauty, currentOverlap);
        }
        return maxBeauty;
    }
};
