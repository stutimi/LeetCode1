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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursionRight(root, 0, res);
        return res;
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> res;
        recursionLeft(root, 0, res);
        return res;
    }

private:
    void recursionRight(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(root->val);
        }
        recursionRight(root->right, level + 1, res);
        recursionRight(root->left, level + 1, res);
    }

    void recursionLeft(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(root->val);
        }
        recursionLeft(root->left, level + 1, res);
        recursionLeft(root->right, level + 1, res);
    }
};
