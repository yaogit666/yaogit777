class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* newHead = new ListNode(NULL);
		newHead->next = head;
		ListNode* fast = newHead;
		ListNode* slow = newHead;
		int i = 0;
		while (fast->next)
		{
			if (i < n)
			{
				fast = fast->next;
				i++;
			}
			else
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		slow->next = slow->next->next;
		return newHead->next;
	}
};