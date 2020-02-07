/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode *p;
		ListNode *Head;
		if (pHead1->val <= pHead2->val)
		{
			Head = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			Head = pHead2;
			pHead2 = pHead2->next;
		}
		p = Head;
		while (pHead1&&pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				p->next = pHead1;
				pHead1 = pHead1->next;
				p = p->next;
			}
			else
			{
				p->next = pHead2;
				pHead2 = pHead2->next;
				p = p->next;
			}
		}
		if (pHead1)
			p->next = pHead1;
		else
			p->next = pHead2;
		return Head;
	}
};