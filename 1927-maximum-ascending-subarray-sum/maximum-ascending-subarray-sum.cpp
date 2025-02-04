class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int r = 1;
        int sum = nums[0];
        int max_sum = nums[0];
        while(r<n){while(r<n and nums[r]> nums[r-1]){
                sum += nums[r];
                r++; }
            max_sum = max(max_sum, sum);
            if(r<n) sum = nums[r];
            r++; }
        return max_sum;
    }
};