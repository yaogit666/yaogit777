/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int> v;
		if (!root)
			return v;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				TreeNode* t = q.front();
				q.pop();
				if (t)
					v.push_back(t->val);
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
		}
		return v;
	}
};