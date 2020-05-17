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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		ListNode* p1 = NULL;
		ListNode* p2 = slow;
		while (p2 != NULL)
		{
			ListNode* tep = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = tep;
		}

		while (p1 != NULL && head != NULL)
		{
			if (p1->val != head->val)
				return false;
			head = head->next;
			p1 = p1->next;
		}
		return true;
	}
};