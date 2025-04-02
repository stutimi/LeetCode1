class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = numeric_limits<long long>::min();
        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                for(int k = j+1; k<n; k++) {
                    ans = max(ans, (long long)(nums[i]-nums[j])*nums[k]);
                }
            }
        }
        
        return ans<0?0:ans;
    }
};