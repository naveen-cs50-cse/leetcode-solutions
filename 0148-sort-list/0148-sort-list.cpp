/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // 1. Split the list into two halves using slow/fast pointers
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Break the connection to create two sub-lists

        // 2. Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // 3. Merge the sorted halves and return
        return merge(left, right);
    }

private:
    // Helper to find the middle of the linked list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // Start fast ahead to get the first-half end
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Standard helper to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Attach the remaining elements of the non-empty list
        tail->next = (list1) ? list1 : list2;
        
        return dummy.next;
    }
};