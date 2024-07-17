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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
                unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        root = deleteNodes(root, to_delete_set, result);
        if (root != nullptr) {
            result.push_back(root);
        }
        return result;
    }
    
private:
    TreeNode* deleteNodes(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& result) {
        if (node == nullptr) {
            return nullptr;
        }
        
        node->left = deleteNodes(node->left, to_delete_set, result);
        node->right = deleteNodes(node->right, to_delete_set, result);
        
        if (to_delete_set.find(node->val) != to_delete_set.end()) {
            if (node->left != nullptr) {
                result.push_back(node->left);
            }
            if (node->right != nullptr) {
                result.push_back(node->right);
            }
            return nullptr;
        }
        
        return node;

    }
};