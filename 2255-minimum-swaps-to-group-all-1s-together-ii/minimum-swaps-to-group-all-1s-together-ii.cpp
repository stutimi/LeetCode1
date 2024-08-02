class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int onesCount = std::count(nums.begin(), nums.end(), 1);
        
        if (onesCount == 0) return 0;
        
        std::vector<int> doubledNums(nums.begin(), nums.end());
        doubledNums.insert(doubledNums.end(), nums.begin(), nums.end());
        
        int currentOnes = 0;
        for (int i = 0; i < onesCount; ++i) {
            if (doubledNums[i] == 1) {
                ++currentOnes;
            }
        }
        
        int maxOnes = currentOnes;
        for (int i = onesCount; i < doubledNums.size(); ++i) {
            if (doubledNums[i] == 1) {
                ++currentOnes;
            }
            if (doubledNums[i - onesCount] == 1) {
                --currentOnes;
            }
            maxOnes = std::max(maxOnes, currentOnes);
        }
        return onesCount - maxOnes;
    }
};