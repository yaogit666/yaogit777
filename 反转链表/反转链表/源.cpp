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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		ListNode * p = pHead;
		ListNode * newHead;
		stack<ListNode *> stack1;
		while (p->next != NULL)
		{
			stack1.push(p);
			p = p->next;
		}
		newHead = p;
		while (!stack1.empty())
		{
			p->next = stack1.top();
			p = p->next;
			stack1.pop();
		}
		p->next = NULL;
		return newHead;
	}
};