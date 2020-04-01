class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int len = prices.size();
		if (k > len / 2)
		{
			vector<vector<int>> dp(len, vector<int>(2, 0));
			dp[0][0] = 0;
			dp[0][1] = -prices[0];
			for (int i = 1; i < len; i++)
			{
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			}
			return dp[len - 1][0];
		}
		else
		{
			vector<vector<vector<int>>> dp(len, vector<vector<int>>(k + 1, vector<int>(2, 0)));
			for (int i = 0; i < len; i++)
			{
				for (int j = k; j >= 1; j--)
				{
					if (i - 1 < 0)
					{
						dp[i][j][0] = 0;
						dp[i][j][1] = -prices[i];
						continue;
					}
					dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
					dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
				}
			}
			return dp[len - 1][k][0];
		}
	}
};