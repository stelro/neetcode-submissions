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
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next_tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_tmp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* tmp_head_next = first->next;
            ListNode* tmp_tail_next = second->next;
            first->next = second;
            second->next = tmp_head_next;
            first = tmp_head_next;
            second = tmp_tail_next;
        }
    }
};
