class Solution {
public:
int upperbound(vector<int>& nums,int n, int target){
    int l = 0;
    int r = n-1;
    int ans = n;
    while(l<=r){
        int mid  = (l+r)/2;
        if(nums[mid]>target){
            ans = min(ans,mid);
            r = mid-1;}
            else{
                l = mid+1;
            }
        }
        return ans;
    }
int lowerbound(vector<int>& nums,int n, int target){
    int l = 0;
    int r = n-1;
    int ans = n;
    while(l<=r){
        int mid  = (l+r)/2;
        if(nums[mid]>=target){
            ans = min(ans,mid);
            r = mid-1;}
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbound(nums,n, target);
        int ub = upperbound(nums,n, target);
        if(lb==ub){
            return {-1,-1};
        }
        else {
            return {lb, ub-1};
        }
    }
};