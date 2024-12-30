class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(); 

        int result = 0;
        int maxTillNow = values[0] + 0; 

        for (int j = 1; j < n; j++) {
            int x = values[j] - j;      
            int y = maxTillNow;         

            result = max(result, x + y); 

            maxTillNow = max(maxTillNow, values[j] + j); 
        }

        return result;
    }
};

  