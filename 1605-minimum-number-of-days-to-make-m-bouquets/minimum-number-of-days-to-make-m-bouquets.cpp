class Solution {
public:
    bool possible(vector<int> &arr, int day, int m, int k) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                cnt++;
                if (cnt == k) {
                    noOfB++;
                    cnt = 0;
                }
            } else {
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB +=(cnt/k);
        return noOfB >= m;
    }
    int minDays(vector<int>& ar, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        if (val > ar.size()) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < ar.size(); i++) {
            mini = min(mini, ar[i]);
            maxi = max(maxi, ar[i]);
        }
        
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(ar, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
