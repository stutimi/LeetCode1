class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // The maximum product can be the product of the last three numbers (the three largest numbers)
        // or the product of the first two numbers (the two smallest numbers) and the last number (the largest number)
        return max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);
    }
};