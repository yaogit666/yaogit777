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
	bool balance = true;
	bool isBalanced(TreeNode* root) {
		height(root);
		return balance;
	}
	int height(TreeNode* t) {
		if (t == nullptr || !balance) return 0;
		int left = height(t->left);
		int right = height(t->right);
		if (abs(left - right) > 1) balance = false;
		return max(left, right) + 1;
	}
};
