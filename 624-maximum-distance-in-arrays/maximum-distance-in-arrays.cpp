class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_value = arrays[0].front();
        int max_value = arrays[0].back();
        int max_distance = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - min_value));
            max_distance = max(max_distance, abs(max_value - arrays[i].front()));
            min_value = min(min_value, arrays[i].front());
            max_value = max(max_value, arrays[i].back());
        }
        return max_distance;
    }
};
