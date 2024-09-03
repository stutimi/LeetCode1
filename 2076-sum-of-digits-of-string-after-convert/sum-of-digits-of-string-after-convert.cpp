class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for (char c : s) {
            num += to_string(c - 'a' + 1);
        }
        int sum = 0;
        while (k--) {
            sum = 0;
            for (char digit : num) {
                sum += digit - '0';
            }
            num = to_string(sum);
        }
        return sum;
    }
};
