class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int lenth = matrix.size();
		int width = matrix[0].size();
		for (int i = 0; i < lenth / 2; i++)
		{
			for (int j = 0; j < width; j++)
			{
				swap(matrix[i][j], matrix[lenth - i - 1][j]);
			}
		}
		for (int i = 1; i < lenth; i++)
		{
			for (int j = 0; j < i; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};