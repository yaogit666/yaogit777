/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* l = head;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int sum = 0;
		int carry = 0;
		while (p1 || p2 || carry)
		{
			sum = 0;
			if (p1)
			{
				sum += p1->val;
				p1 = p1->next;
			}
			if (p2)
			{
				sum += p2->val;
				p2 = p2->next;
			}
			sum += carry;
			ListNode* ll = new ListNode(sum % 10);
			l->next = ll;
			l = l->next;
			carry = sum / 10;
		}
		return head->next;
	}
};