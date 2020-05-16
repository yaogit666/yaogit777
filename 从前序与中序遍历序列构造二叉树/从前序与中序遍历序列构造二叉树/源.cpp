class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0)
			return NULL;
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
		//�������ڵ�
		TreeNode* root = new TreeNode(preorder[ps]);
		root->left = NULL;
		root->right = NULL;

		//������������Ѱ�Ҹ��ڵ�
		int i = is;
		while (i <= ie && preorder[ps] != inorder[i])
			++i;
		//iָ�����������и��ڵ��λ��
		int ll = i - is;//�����������г���
		int rl = ie - i;//�����������г���

		//������������        
		if (ll > 0) {
			root->left = build(preorder, ps + 1, ps + ll, inorder, is, is + ll - 1);
		}
		if (rl > 0) {
			root->right = build(preorder, ps + ll + 1, pe, inorder, is + ll + 1, ie);
		}
		return root;

	}
};