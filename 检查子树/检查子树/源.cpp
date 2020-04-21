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
	bool checkSubTree(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL)
			return true;
		if (t1 == NULL || t2 == NULL)
			return false;
		bool b = (t1->val == t2->val);

		return (b && dfs(t1, t2)) || (checkSubTree(t1->left, t2)) || (checkSubTree(t1->right, t2));
	}

	bool dfs(TreeNode* t1, TreeNode* t2)
	{
		if (t1 == NULL && t2 == NULL)
			return true;
		if (t1 == NULL || t2 == NULL)
			return false;

		if (t1->val == t2->val)
			return dfs(t1->left, t2->left) && dfs(t1->right, t2->right);
		else
			return false;
	}
};