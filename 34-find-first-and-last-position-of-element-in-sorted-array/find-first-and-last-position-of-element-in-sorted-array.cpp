#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb =  lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int ub =  upper_bound(nums.begin(), nums.end(), target)- nums.begin();
        
        if (lb == ub) {
            return {-1, -1};
        } else {
            return {lb, ub - 1};
        }
    }
};
