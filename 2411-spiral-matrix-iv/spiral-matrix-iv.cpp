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
class Solution {
public:
    

// Definition for singly-linked list.
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    // Step 1: Initialize the matrix filled with -1
    vector<vector<int>> matrix(m, vector<int>(n, -1));

    // Step 2: Define the boundaries for spiral traversal
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    // Step 3: Traverse through the matrix and fill it
    ListNode* current = head;
    while (top <= bottom && left <= right && current != nullptr) {
        // Traverse from left to right along the top row
        for (int j = left; j <= right && current != nullptr; ++j) {
            matrix[top][j] = current->val;
            current = current->next;
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom && current != nullptr; ++i) {
            matrix[i][right] = current->val;
            current = current->next;
        }
        right--; // Move the right boundary left

        // Traverse from right to left along the bottom row
        for (int j = right; j >= left && current != nullptr; --j) {
            matrix[bottom][j] = current->val;
            current = current->next;
        }
        bottom--; // Move the bottom boundary up

        // Traverse from bottom to top along the left column
        for (int i = bottom; i >= top && current != nullptr; --i) {
            matrix[i][left] = current->val;
            current = current->next;
        }
        left++; // Move the left boundary right
    }

    // Step 4: Return the filled matrix
    return matrix;
}
};