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
	vector<int> inorderTraversal(TreeNode* root) {
		middleOrder(root);
		return v;
	}
	void middleOrder(TreeNode* root)
	{
		if (root == NULL)
			return;
		middleOrder(root->left);
		v.push_back(root->val);
		middleOrder(root->right);
	}
};