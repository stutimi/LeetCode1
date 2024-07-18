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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast == NULL) return head; // If n is greater than the length of the list
            fast = fast->next;
        }
        
        // If fast pointer reaches the end, we need to remove the head node
        if (fast == NULL) return head->next;
        
        // Move both pointers until fast reaches the end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head; 

    }
};