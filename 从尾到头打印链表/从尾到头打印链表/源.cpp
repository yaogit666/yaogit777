class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		ListNode* p = NULL;
		p = head;
		stack<int> st;
		while (p != NULL)
		{
			st.push(p->val);
			p = p->next;
		}
		while (!st.empty())
		{
			v.push_back(st.top());
			st.pop();
		}
		return v;
	}
};