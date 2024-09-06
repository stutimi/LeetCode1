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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Dummy node to handle edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (valuesToRemove.find(current->next->val) != valuesToRemove.end()) {
                ListNode* nodeToRemove = current->next;
                current->next = current->next->next;
                delete nodeToRemove;  // Free the memory of the removed node
            } else {
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;  // Free the memory of the dummy node
        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

    
