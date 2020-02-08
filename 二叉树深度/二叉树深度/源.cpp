class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		return pRoot == NULL ? 0 : max(TreeDepth(pRoot->right), TreeDepth(pRoot->left)) + 1;
	}
};