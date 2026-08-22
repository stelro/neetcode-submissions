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
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_half_curr = slow->next;
        slow->next = nullptr;


        ListNode* second_half = nullptr;
        while (second_half_curr) {
            ListNode* tmp_next = second_half_curr->next;
            second_half_curr->next = second_half;
            second_half = second_half_curr;
            second_half_curr = tmp_next;
        }

        
        ListNode* first = head;
        ListNode* second = second_half;

        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;

        }  
    }
};
