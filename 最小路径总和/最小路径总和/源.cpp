class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.empty() || grid[0].empty())
			return 0;

		int N = grid.size();
		int M = grid[0].size();

		vector<vector<int>> v(N, vector<int>(M, 0));
		v[0][0] = grid[0][0];

		for (int i = 1; i < N; i++)
		{
			v[i][0] = grid[i][0] + v[i - 1][0];
		}
		for (int i = 1; i < M; i++)
		{
			v[0][i] = grid[0][i] + v[0][i - 1];
		}

		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
			}
		}

		return v[N - 1][M - 1];
	}
};