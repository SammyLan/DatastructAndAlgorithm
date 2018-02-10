#include "ComonDef.h"


//https://leetcode.com/problems/add-two-numbers/description/
NAMESPACE_ANONYMOUS_BEGIN()
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	void adjust(int &pre, ListNode * & preNode,int & sum) {
		pre = (sum >= 10);
		if (pre != 0) {
			sum -= 10;
		}
		ListNode * cur = new ListNode(sum);
		preNode->next = cur;
		preNode = cur;
	}

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1); // Í·½Úµã
		int pre = 0;
		ListNode * preNode = &dummy;
		while (l1 != nullptr && l2 != nullptr) {
			int sum = pre + l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
			adjust(pre, preNode, sum);
		}
		ListNode * tmp = l1 ==nullptr ?l2:l1;
		while (tmp != nullptr) {
			int sum = pre + tmp->val;
			tmp = tmp->next;
			adjust(pre, preNode, sum);
		}
		if (pre != 0) {
			preNode->next = new ListNode(pre);
		}
		return dummy.next;
	}
};
NAMESPACE_ANONYMOUS_END()