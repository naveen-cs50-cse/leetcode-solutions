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
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // move fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // move both until fast reaches end
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // delete node
    slow->next = slow->next->next;

    return dummy->next;
}
    
};