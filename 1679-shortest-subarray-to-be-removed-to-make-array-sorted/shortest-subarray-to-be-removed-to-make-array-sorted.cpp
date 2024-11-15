class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left + 1 < n && arr[left] <= arr[left + 1]) 
            left++;
        while (right - 1 >= 0 && arr[right - 1] <= arr[right]) 
            right--; 
        if (left >= right) 
            return 0;
        int ans = right; 
        int l = 0, r = right;
        while (l <= left) {
            while (r < n && arr[r] < arr[l]) 
                r++;
            ans = min(ans, r - l - 1);
            l++;
        }
        return ans;
    }
};
