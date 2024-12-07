class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int operations = 0;
            for (int num : nums) {
                operations += (num + mid - 1) / mid - 1; 
            }
            if (operations <= maxOperations) {
                result = mid;  
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return result;
    }
};

