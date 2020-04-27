class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> v;
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return v;
		int on = 0;
		int down = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		while (1)
		{
			for (int i = left; i <= right; i++)
			{
				v.push_back(matrix[on][i]);
			}
			++on;
			if (on > down)
				break;
			for (int i = on; i <= down; i++)
			{
				v.push_back(matrix[i][right]);
			}
			--right;
			if (right < left)
				break;
			for (int i = right; i >= left; i--)
			{
				v.push_back(matrix[down][i]);
			}
			--down;
			if (down < on)
				break;
			for (int i = down; i >= on; i--)
			{
				v.push_back(matrix[i][left]);
			}
			++left;
			if (left > right)
				break;
		}
		return v;
	}
};