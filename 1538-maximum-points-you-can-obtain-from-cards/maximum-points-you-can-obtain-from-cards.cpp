class Solution {
public:
   
    int maxScore(vector<int>& cardScore, int k) {
        int lSum = 0, rSum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            lSum += cardScore[i];
      
            maxSum = lSum;
        }

        int rightIndex = cardScore.size() - 1;
        
        for (int i = k - 1; i >= 0; i--) {
            
            lSum -= cardScore[i];   
            
            rSum += cardScore[rightIndex];  
           
            rightIndex--; 
            maxSum = max(maxSum, lSum + rSum);
        }

        return maxSum; 
    }

};