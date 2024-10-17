class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); 
        stack<int> stk; 
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!stk.empty() && nums[stk.top()] < num) {
                result[stk.top()] = num;
                stk.pop();
            }
            if (i < n) {
                stk.push(i);
            }
        }
        
        return result;
    }
};
