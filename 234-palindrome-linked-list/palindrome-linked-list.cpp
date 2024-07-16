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
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalfStart = reverseLinkedList(slow->next);
        ListNode* firstHalfStart = head;
        ListNode* secondHalfCopy = secondHalfStart; 
        while (secondHalfStart != NULL) {
            if (firstHalfStart->val != secondHalfStart->val) {
                reverseLinkedList(secondHalfCopy); 
                return false;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfStart = secondHalfStart->next;
        }
        reverseLinkedList(secondHalfCopy);
        return true;
    }
};