class Solution {
public:
    double myPow(double x, int n) {
        long long m = n; 
        double ans = 1.0;
        if (m < 0) {
            x = 1 / x; 
            m = -m;   
        }
        while (m > 0) {
            if (m%2 == 1) { 
                ans*= x;
                m -= 1;
            } else { 
                x *= x;
                m /= 2;
            }
        }
        return ans;
    }
};
