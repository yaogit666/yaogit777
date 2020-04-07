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
	vector<vector<int>> res;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return res;
		vector<int> path;
		IsSum(path, root, sum);
		return res;
	}
	void IsSum(vector<int>& path, TreeNode* root, int sum)
	{
		sum -= root->val;
		path.push_back(root->val);
		if (sum == 0 && root->left == NULL && root->right == NULL)
		{
			res.push_back(path);
		}
		if (root->left != NULL)
		{
			IsSum(path, root->left, sum);
		}
		if (root->right != NULL)
		{
			IsSum(path, root->right, sum);
		}
		path.pop_back();
		sum += root->val;
	}
};