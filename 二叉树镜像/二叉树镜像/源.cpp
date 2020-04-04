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
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL)
			return root;
		TreeNode* p = mirrorTree(root->left);
		TreeNode* q = mirrorTree(root->right);
		root->left = q;
		root->right = p;
		return root;
	}
};