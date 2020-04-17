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
	vector<int> v;
	int res = 0;
	int pathSum(TreeNode* root, int sum) {
		path(root, sum, 0);
		return res;
	}
	void path(TreeNode* root, int sum, int s)
	{
		if (!root)
			return;
		v.push_back(root->val);
		s += root->val;
		int t = s;
		if (s == sum)
			res += 1;
		for (int i = 0; i < v.size() - 1; i++)
		{
			t -= v[i];
			if (t == sum)
				res += 1;
		}
		if (root->left)
		{
			path(root->left, sum, s);
			v.pop_back();
		}
		if (root->right)
		{
			path(root->right, sum, s);
			v.pop_back();
		}
	}
};