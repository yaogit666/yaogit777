class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
		int m = 0;
		while (dp[K][m] < N)
		{
			m++;
			for (int i = 1; i <= K; i++)
			{
				dp[i][m] = dp[i][m - 1] + dp[i - 1][m - 1] + 1;
			}
		}
		return m;
	}
};