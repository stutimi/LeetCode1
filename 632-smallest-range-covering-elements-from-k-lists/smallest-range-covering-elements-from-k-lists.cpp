class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store the current smallest elements from each list
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        int k = nums.size();  // Number of lists
        int currentMax = INT_MIN;  // Track the largest element in the current range
        
        // Initialize the heap with the first element from each list
        for (int i = 0; i < k; ++i) {
            minHeap.push({nums[i][0], i, 0});  // {value, index_of_list, index_in_list}
            currentMax = max(currentMax, nums[i][0]);
        }
        
        // Variables to track the smallest range
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while (!minHeap.empty()) {
            auto minElement = minHeap.top();
            minHeap.pop();
            
            int currentMin = minElement[0];  // The smallest element in the current range
            int listIndex = minElement[1];   // The list from which this element comes
            int elementIndex = minElement[2];  // The index of this element in the list
            
            // Update the range if we found a smaller one
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
            // If there is another element in the same list, push it into the heap
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextValue = nums[listIndex][elementIndex + 1];
                minHeap.push({nextValue, listIndex, elementIndex + 1});
                currentMax = max(currentMax, nextValue);  // Update the current max
            } else {
                // If we can't add more elements from this list, break the loop
                break;
            }
        }
        
        return {rangeStart, rangeEnd};
    }
};
