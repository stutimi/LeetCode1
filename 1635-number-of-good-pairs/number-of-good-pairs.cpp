class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : nums) {
            if (freq.find(num) != freq.end()) {
                count += freq[num];
            }
            freq[num]++;
        }
        
        return count;
    }
};