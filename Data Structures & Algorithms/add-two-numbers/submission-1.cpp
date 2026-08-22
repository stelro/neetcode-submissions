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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
	
        ListNode dummy(0);
        ListNode* result = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {

            int a1 = (l1) ? l1->val : 0;
            int a2 = (l2) ? l2->val : 0;

            int r = a1 + a2 + carry;
            carry = r / 10;
            r = r % 10;
            result->next = new ListNode(r);
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            result = result->next;
        }

        if (carry) {
            result->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
