
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
	vector<ListNode*> listOfDepth(TreeNode* tree) {
		vector<ListNode*> v;
		queue<TreeNode*> q;
		q.push(tree);
		while (!q.empty())
		{
			ListNode* L = new ListNode(-1);
			ListNode* head = L;
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* t1 = q.front();
				ListNode* t2 = new ListNode(t1->val);
				head->next = t2;
				head = head->next;
				q.pop();
				if (t1->left)
					q.push(t1->left);
				if (t1->right)
					q.push(t1->right);
			}
			v.push_back(L->next);
		}
		return v;
	}
};
