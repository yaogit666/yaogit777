class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		vector<vector<int>> dp(len, vector<int>(len, 0));
		for (int i = 0; i < len; i++)
		{
			dp[i][i] = 1;
		}
		int left = 0;
		int right = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (j - i < 3 && s[i] == s[j])
					dp[i][j] = 1;
				else if (j - i >= 3 && dp[i + 1][j - 1] && s[i] == s[j])
					dp[i][j] = 1;
				else
					dp[i][j] = 0;

				if (dp[i][j] && right - left < j - i)
				{
					right = j;
					left = i;
				}
			}
		}
		string str = s.substr(left, right - left + 1);
		return str;
	}
};