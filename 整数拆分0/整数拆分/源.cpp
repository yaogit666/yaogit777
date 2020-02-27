class Solution {
public:
	int integerBreak(int n) {
		vector<int> v(n + 1, 0);
		v[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				v[i] = max(v[i], max(v[j], j) * (i - j));
			}
		}
		return v[n];
	}
};