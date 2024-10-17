class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;

        for (char digit : num) {
            while (!stk.empty() && k > 0 && stk.top() > digit) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }
        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        while (result.length() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }
        return result.empty() ? "0" : result;
    }
};
