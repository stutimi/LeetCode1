class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            cnt += ans & 1;  
            ans >>= 1;       
        }
        return cnt;
    }
};
