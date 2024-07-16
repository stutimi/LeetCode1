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
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;

        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        string steps;
        for (int j = i; j < pathToStart.size(); j++) {
            steps += 'U';
        }
        steps += pathToDest.substr(i);

        return steps;
    }
};

TreeNode* buildTree(const vector<int>& values) {
    if (values.empty()) return nullptr;

    unordered_map<int, TreeNode*> nodes;
    for (int val : values) {
        if (val != -1) nodes[val] = new TreeNode(val);
    }

    queue<TreeNode*> q;
    q.push(nodes[values[0]]);
    int index = 1;

    while (!q.empty() && index < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (index < values.size() && values[index] != -1) {
            current->left = nodes[values[index]];
            q.push(current->left);
        }
        index++;
        if (index < values.size() && values[index] != -1) {
            current->right = nodes[values[index]];
            q.push(current->right);
        }
        index++;
    }

    return nodes[values[0]];
}

