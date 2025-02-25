class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n =arr.size(), MOD = 1e9+7, odd =0, even =1, sum =0, res =0;
        for (int num : arr) {
            sum = (sum+num) %2;
            res = (res+(sum ? even : odd)) %MOD;
            sum ?++odd : ++even;
        } 
        return res;
    }
};
