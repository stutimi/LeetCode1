class Solution {
public:
    int findmax(const vector<int>& piles) {
        int maxBananas = 0;
        for (int pile : piles) {
            maxBananas = max(maxBananas, pile);
        }
        return maxBananas;
    }
    int calculateTotalHours(const vector<int>& piles, int k) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k; 
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; 
        int right = findmax(piles); 
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = calculateTotalHours(piles, mid);
            if (hours <= h) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }
};
