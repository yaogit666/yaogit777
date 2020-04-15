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
	ListNode* partition(ListNode* head, int x) {
		ListNode* l1 = new ListNode(0);
		ListNode* head1 = l1;
		ListNode* l2 = new ListNode(0);
		ListNode* head2 = l2;
		while (head)
		{
			if (head->val < x)
			{
				l1->next = head;
				l1 = l1->next;
			}
			else
			{
				l2->next = head;
				l2 = l2->next;
			}
			head = head->next;
		}
		l1->next = head2->next;
		l2->next = NULL;
		return head1->next;
	}
};