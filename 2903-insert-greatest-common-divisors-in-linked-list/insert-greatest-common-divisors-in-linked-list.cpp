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
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if (!head || !head->next) return head; // If there is only one node, return as is
    
    ListNode* current = head;
    
    // Traverse the list until the last node
    while (current && current->next) {
        int gcdValue = gcd(current->val, current->next->val); // Find GCD between current and next node values
        
        // Create a new node with the GCD value
        ListNode* newNode = new ListNode(gcdValue);
        
        // Insert the new node between current and next
        newNode->next = current->next;
        current->next = newNode;
        
        // Move to the node after the newly inserted node
        current = newNode->next;
    }
    
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
};