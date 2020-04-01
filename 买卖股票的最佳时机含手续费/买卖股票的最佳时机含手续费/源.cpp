class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		if (prices.size() == 0)
			return 0;
		int len = prices.size();
		vector<vector<int>> dp(len, vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = -prices[0] - fee;
		for (int i = 1; i < len; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
		}
		return dp[len - 1][0];
	}
};