/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;
		ListNode* fast = pHead;
		ListNode* slow = pHead;
		while (1)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				break;
			}
		}
		ListNode* newN = pHead;
		while (newN != slow)
		{
			newN = newN->next;
			slow = slow->next;
		}
		return newN;
	}
};