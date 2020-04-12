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
	TreeNode* dfs(vector<int>& nums, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = (right + left) >> 1;
		TreeNode* tree = new TreeNode(nums[mid]);
		tree->left = dfs(nums, left, mid - 1);
		tree->right = dfs(nums, mid + 1, right);
		return tree;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		TreeNode* tree = dfs(nums, 0, nums.size() - 1);
		return tree;
	}
};