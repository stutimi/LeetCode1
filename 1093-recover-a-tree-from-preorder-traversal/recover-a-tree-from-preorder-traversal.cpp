/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int level, value;
        TreeNode* node;
        stack<TreeNode*> stk;
        
        for(int i = 0; i < traversal.size(); ) {
            level = 0;
            value = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                level++;
                i++;
            }
            while (i < traversal.size() && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            node = new TreeNode(value);
            while (stk.size() > level) {
                stk.pop();
            }
            if (!stk.empty()) {
                if (!stk.top()->left) {
                    stk.top()->left = node;
                } else {
                    stk.top()->right = node;
                }
            }
            stk.push(node);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        
        return stk.top();
    }
};
