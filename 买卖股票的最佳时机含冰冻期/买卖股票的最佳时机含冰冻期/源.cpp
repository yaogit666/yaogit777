class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int len = prices.size();
		vector<vector<int>> dp(len, vector<int>(2, 0));
		if (len > 1)
		{
			dp[0][0] = 0;
			dp[0][1] = -prices[0];
			dp[1][0] = max(0, prices[1] - prices[0]);
			dp[1][1] = max(-prices[0], -prices[1]);
			for (int i = 2; i < len; i++)
			{
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
				dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
			}
			return dp[len - 1][0];
		}
		else
		{
			return 0;
		}
	}
};