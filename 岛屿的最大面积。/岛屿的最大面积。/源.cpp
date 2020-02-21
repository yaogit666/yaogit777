class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int area = 0;
		int maxArea = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				area = Find(grid, i, j);
				maxArea = max(maxArea, area);
			}
		}
		return maxArea;
	}

	int Find(vector<vector<int>>& grid, int i, int j)
	{
		if (i == grid.size() || j == grid[0].size() || i < 0 || j < 0)
		{
			return 0;
		}
		if (grid[i][j] == 1)
		{
			grid[i][j] = 0;
			return 1 + Find(grid, i + 1, j) + Find(grid, i, j + 1) + Find(grid, i - 1, j) + Find(grid, i, j - 1);
		}
		return 0;
	}
};