class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max = 0 ;
int cnt = 0;
for(int i = 0; i<nums.size(); i++){
    if(nums[i]==1){
        cnt++;
        Max = max(Max,cnt);
    }
    else {
        cnt = 0;
    }
}
return Max;
    }
};