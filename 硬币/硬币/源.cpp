class Solution {
public:
	int waysToChange(int n) {
		vector<vector<int>> dp(4, vector<int>(n + 1, 1));
		int v[4] = { 1,5,10,25 };
		for (int i = 1; i < 4; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j >= v[i])
				{
					dp[i][j] = (dp[i - 1][j] + dp[i][j - v[i]]) % 1000000007;
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[3][n];
	}
};
