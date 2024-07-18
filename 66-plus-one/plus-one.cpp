class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
                int n = digits.size();
        
        // Iterate from the last digit to the first
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                // If the current digit is less than 9, increment it by 1 and return the result
                digits[i]++;
                return digits;
            }
            // If the current digit is 9, set it to 0
            digits[i] = 0;
        }
        
        // If all digits were 9, we need to add a leading 1
        digits.insert(digits.begin(), 1);
        return digits;

    }
};