/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Helper function to check if the linked list matches the binary tree starting from this node
    bool dfs(ListNode* head, TreeNode* root) {
        // Base case: if we've reached the end of the linked list, return true
        if (!head) return true;
        // If the tree node is null or doesn't match the current linked list node, return false
        if (!root || root->val != head->val) return false;
        
        // Recursively check both left and right children of the tree node
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        // Base case: if the tree node is null, return false
        if (!root) return false;
        
        // Check if the current node matches the linked list, or check the left and right children
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
