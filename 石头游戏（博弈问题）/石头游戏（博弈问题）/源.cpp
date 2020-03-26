#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int stoneGame(vector<int> &v)
{
	int len = v.size();
	vector < vector<pair<int, int>>> dp(len, vector<pair<int ,int>>(len,{0, 0}));
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = {v[i], 0};
	}
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = i+1; j < len; j++)
		{
			if (v[i] + dp[i + 1][j].second > v[j] + dp[i][j - 1].second)
			{
				dp[i][j].first = v[i] + dp[i + 1][j].second;
				dp[i][j].second = dp[i+1][j].first;
			}
			else
			{
				dp[i][j].first = v[j] + dp[i][j - 1].second;
				dp[i][j].second = dp[i][j-1].first;
			}
		}
	}
	int res = dp[0][len - 1].first - dp[0][len - 1].second;
	return res;
}
int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get()=='\n')
			break;
	}
	cout << stoneGame(v) << endl;
	system("pause");
	return 0;
}