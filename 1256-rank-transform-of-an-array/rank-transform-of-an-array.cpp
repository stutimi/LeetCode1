class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Copy the array and sort it
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // Step 2: Create a map to store ranks
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        // Assign ranks to unique elements
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        // Step 3: Transform the original array using the rank map
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};
