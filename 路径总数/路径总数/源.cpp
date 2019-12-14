class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

		int N = obstacleGrid.size();
		int M = obstacleGrid[0].size();

		vector<vector<int>> v(N, vector<int>(M, 0));

		for (int i = 0; i < N; i++)
		{
			if (obstacleGrid[i][0] == 1)
				break;
			else
				v[i][0] = 1;
		}
		for (int i = 0; i < M; i++)
		{
			if (obstacleGrid[0][i] == 1)
				break;
			else
				v[0][i] = 1;
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				if (obstacleGrid[i][j])
					v[i][j] = 0;
				else
					v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[N - 1][M - 1];
	}
};