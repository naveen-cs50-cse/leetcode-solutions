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
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes for the less-than and greater-than-or-equal lists
        ListNode lessHead(0);
        ListNode greaterHead(0);

        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;

        // Traverse the original list and split nodes into two buckets
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Terminate the greater list to avoid cycles
        greater->next = nullptr;
        // Connect less list with greater list
        less->next = greaterHead.next;

        return lessHead.next;
    }
};