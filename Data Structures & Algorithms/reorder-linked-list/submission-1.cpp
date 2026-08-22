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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Take half of the list
        ListNode* half_curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (half_curr) {
            ListNode* tmp_next = half_curr->next;
            half_curr->next = prev;
            prev = half_curr;
            half_curr = tmp_next;
        }

        ListNode* first_half = head;
        ListNode* second_half = prev;

        while (second_half) {
            ListNode* first_half_next = first_half->next;
            ListNode* second_half_next = second_half->next;

            first_half->next = second_half;
            second_half->next = first_half_next;

            first_half = first_half_next;
            second_half = second_half_next;
        }
    }
};
