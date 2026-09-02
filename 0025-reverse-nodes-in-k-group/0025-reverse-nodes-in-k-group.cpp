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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes available
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) return head; // Less than k nodes left, leave as is
            curr = curr->next;
        }

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        curr = head;
        
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // head is now the tail of the reversed group; reconnect to the rest
        head->next = reverseKGroup(curr, k);

        return prev; // prev is the new head of this reversed group
    }
};