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
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to handle potential deletion of the head node
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if current node has duplicates
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Discard all duplicates by advancing prev->next
                prev->next = head->next;
            } else {
                // No duplicate for this value, move prev forward
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy.next;
    }
};
