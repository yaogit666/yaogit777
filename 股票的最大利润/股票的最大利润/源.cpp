class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n1 = INT_MAX;
		int n2 = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			n1 = min(n1, prices[i]);
			n2 = max(n2, prices[i] - n1);
		}
		return n2;
	}
};