class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int ast : asteroids) {
            bool alive = true;

            while (alive && ast < 0 && !stk.empty() && stk.top() > 0) {
                if (stk.top() < -ast) {
                    stk.pop();
                } else if (stk.top() == -ast) {
                    stk.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) {
                stk.push(ast);
            }
        }

        vector<int> result(stk.size());
        for (int i = stk.size() - 1; i >= 0; --i) {
            result[i] = stk.top();
            stk.pop();
        }

        return result;
    }
};

