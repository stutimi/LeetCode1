class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;  // To track the current balance of brackets
        int maxImbalance = 0; // To track the maximum imbalance encountered
        
        // Traverse the string to calculate balance
        for (char c : s) {
            if (c == '[') {
                balance++; // Increment balance for opening bracket
            } else {
                balance--; // Decrement balance for closing bracket
            }
            
            // If balance goes negative, we have an imbalance
            if (balance < 0) {
                maxImbalance++;
                balance = 0; // Reset balance to zero after handling imbalance
            }
        }
        
        // Each swap can fix two imbalances
        return (maxImbalance + 1) / 2; // Return the number of swaps needed
    }
};

