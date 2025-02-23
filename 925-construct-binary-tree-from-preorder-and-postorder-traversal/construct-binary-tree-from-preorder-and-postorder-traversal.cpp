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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int,int>postMap;
        for (int i=0; i<post.size(); i++) {
            postMap[post[i]] = i;
        }
        int preIndex = 0;
        return construct(pre, post, postMap, preIndex, 0, post.size() - 1);
    }

private:
    TreeNode* construct(vector<int>& pre, vector<int>& post, unordered_map<int, int>& postMap, 
                        int& preIndex, int postStart, int postEnd) {
        if (preIndex >= pre.size() || postStart > postEnd) 
            return nullptr;

        TreeNode* node = new TreeNode(pre[preIndex++]);

        if (preIndex < pre.size() && postStart <= postEnd) {
            int leftRootIndex = postMap[pre[preIndex]];
            if (leftRootIndex <= postEnd) {
                node->left = construct(pre, post, postMap, preIndex, postStart, leftRootIndex);
                node->right = construct(pre, post, postMap, preIndex, leftRootIndex + 1, postEnd - 1);
            }
        }
        return node;
    }
};

