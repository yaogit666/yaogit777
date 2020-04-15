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
	ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == nullptr)
			return head;
		unordered_set <int> s;
		s.insert(head->val);
		ListNode* p = head;
		while (p->next)
		{
			if (s.find(p->next->val) != s.end())
				p->next = p->next->next;
			else
			{
				s.insert(p->next->val);
				p = p->next;
			}
		}
		return head;
	}
};