class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		return (!root->left || !root->right) ? max(minDepth(root->left), minDepth(root->right)) + 1 :
			min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

