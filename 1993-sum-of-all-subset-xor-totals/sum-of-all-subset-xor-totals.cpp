class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }

private:
    int helper(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) return currentXOR;
        return helper(nums, index + 1, currentXOR ^ nums[index]) + 
               helper(nums, index + 1, currentXOR);
    }
};
