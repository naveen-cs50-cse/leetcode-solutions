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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length of the list and locate the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Connect the tail to the head to make it circular
        tail->next = head;

        // Step 3: Find the new tail position: (length - k % length - 1)
        k = k % length;
        int stepsToNewTail = length - k - 1;
        
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Set the new head and break the circular connection
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};