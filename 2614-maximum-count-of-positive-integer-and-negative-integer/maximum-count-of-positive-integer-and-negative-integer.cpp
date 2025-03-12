class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int cnt = 0;
        int cnt1 =0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0) cnt++;
            else if(nums[i]>0)  cnt1++;
        }
        return max(cnt,cnt1);
    }
};