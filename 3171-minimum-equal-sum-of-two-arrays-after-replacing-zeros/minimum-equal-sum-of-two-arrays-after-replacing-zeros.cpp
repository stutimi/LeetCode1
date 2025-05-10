class Solution {
public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sumNums1 = 0; 
        long long sumNums2 = 0; 
        bool hasZero = false;  

        for (int num : nums1) {
            hasZero |= num == 0;  
            sumNums1 += std::max(num, 1); 
        }
        for (int num : nums2) {
            sumNums2 += std::max(num, 1);

        }
        if (sumNums1 > sumNums2) {
            return minSum(nums2, nums1);
        }

      if (sumNums1 == sumNums2) {
          return sumNums1;
       }
return hasZero ? sumNums2 : -1;
    }
};