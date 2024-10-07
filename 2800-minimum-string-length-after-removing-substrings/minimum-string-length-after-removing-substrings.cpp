class Solution {
public:
    int minLength(string s) {
        stack<char> st; // stack to store characters
        for (char c : s) {
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop(); // remove the pair if "AB" or "CD" is found
            } else {
                st.push(c); // otherwise, add the character to the stack
            }
        }
        return st.size(); // the size of the stack gives the minimum possible length
    }
};
