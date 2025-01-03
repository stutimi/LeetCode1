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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        function<void(TreeNode*)> postorder = [&](TreeNode* node) {
            if (!node) return;
            postorder(node->left); 
            postorder(node->right); 
            result.push_back(node->val); 
        };
        postorder(root);
        return result;
    }
};
