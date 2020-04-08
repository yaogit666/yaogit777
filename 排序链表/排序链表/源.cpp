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
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* l;
		while (fast != NULL && fast->next != NULL)
		{
			l = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		l->next = NULL;
		return Sort(sortList(head), sortList(slow));
	}

	ListNode* Sort(ListNode* l1, ListNode*l2)
	{
		ListNode* l = new ListNode(1);
		ListNode* head = l;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				l->next = l1;
				l1 = l1->next;
			}
			else
			{
				l->next = l2;
				l2 = l2->next;
			}
			l = l->next;
		}
		if (l1 == NULL)
			l->next = l2;
		else
			l->next = l1;
		return head->next;
	}
};