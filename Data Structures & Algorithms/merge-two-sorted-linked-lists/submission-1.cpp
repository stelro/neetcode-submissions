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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode dummy(0);
        ListNode* result = &dummy;
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                result->next = curr1;
                curr1 = curr1->next;
            } else {
                result->next = curr2;
                curr2 = curr2->next;
            }

            result = result->next;
        }

        while (curr1) {
            result->next = curr1;
            curr1 = curr1->next;
            result = result->next;
        }

        while (curr2) {
            result->next = curr2;
            curr2 = curr2->next;
            result = result->next;
        }

        return dummy.next;
    }
};
