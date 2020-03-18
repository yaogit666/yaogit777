class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;

		int row = 0;
		int col = matrix[0].size() - 1;

		int end_row = matrix.size() - 1;
		int end_col = 0;

		while (row <= end_row && col >= end_col)
		{
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] > target)
				col--;
			else if (matrix[row][col] < target)
				row++;
		}
		return false;
	}
};