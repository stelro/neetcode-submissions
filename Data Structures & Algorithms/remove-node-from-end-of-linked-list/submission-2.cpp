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
    ListNode* removeNthFromEnd(ListNode* node, int n) {
        ListNode* slow = node;
	ListNode* fast = node;

	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}

	if (fast == nullptr) {
		return node->next;
	}

	while (fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = slow->next->next;

	return node;
    }
};
