class Solution {
public:
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0; 
        for (int num : nums) {
            maxOr |= num; 
        }
        
        int count = 0;
        
        backtrack(nums, 0, 0, maxOr, count);
        return count;
    }
    
    void backtrack(vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++; 
            }
            return;
        }

        backtrack(nums, index + 1, currentOr | nums[index], maxOr, count);
        
        backtrack(nums, index + 1, currentOr, maxOr, count);
    }
};