class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto & c:nums){
            if(c<pivot){
                ans.push_back(c);
            }
        }
        for(auto & c: nums){
            if(c==pivot){
                ans.push_back(c);
            }
        }
        for(auto& c:nums){
            if(c>pivot){
                ans.push_back(c);
            }
        }
        return ans;
    }
};