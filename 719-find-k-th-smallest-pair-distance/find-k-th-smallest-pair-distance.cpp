class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    int countPairs(const std::vector<int>& nums, int mid) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i;
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                ++j;
            }
            count += (j - i - 1);
        }
        return count;
    }
};
