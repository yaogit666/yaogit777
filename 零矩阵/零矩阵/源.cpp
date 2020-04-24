class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<int>lenth(matrix.size(), 0);
		vector<int>wide(matrix[0].size(), 0);
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					lenth[i] = 1;
					wide[j] = 1;
				}
			}
		}

		for (int i = 0; i < lenth.size(); i++)
		{
			if (lenth[i] == 1)
			{
				for (int j = 0; j < matrix[0].size(); j++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < wide.size(); i++)
		{
			if (wide[i] == 1)
			{
				for (int j = 0; j < matrix.size(); j++)
				{
					matrix[j][i] = 0;
				}
			}
		}
	}
};