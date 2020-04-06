class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		bool res = true;
		if (postorder.empty())
			return res;
		res = Finder(postorder, 0, postorder.size() - 1);
		return res;
	}

	bool Finder(vector<int>& postorder, int start, int end)
	{
		if (postorder.empty() || start > end)
			return true;
		int root = postorder[end];
		int i = start;
		for (; i < end; i++)
		{
			if (postorder[i] > root)
				break;
		}
		for (int j = i; j < end; j++)
		{
			if (postorder[j] < root)
				return false;
		}
		bool left = true;
		if (i > start)
		{
			left = Finder(postorder, start, i - 1);
		}
		bool right = true;
		if (i < end - 1)
		{
			right = Finder(postorder, i, end - 1);
		}
		return left && right;
	}
};