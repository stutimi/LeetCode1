class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> uniqueElements(nums.begin(),nums.end());
        int o = 0;
        for(int num: uniqueElements){
            if(num>k){
                o++;
            } else if (num<k){
                return -1;
            }
        }
        return o;
    }
};