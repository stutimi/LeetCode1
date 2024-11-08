class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxNum = (1 << maximumBit) - 1;  
        int currentXor = 0;
        
        for (int num : nums) {
            currentXor ^= num;
        }
        
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i) {
            result[i] = maxNum ^ currentXor; 
            currentXor ^= nums[n - 1 - i];   
        }
        
        return result;
    }
};
