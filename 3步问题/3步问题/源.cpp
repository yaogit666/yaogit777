class Solution {
public:
	int waysToStep(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		if (n == 3) return 4;
		vector<long> v(n, 0);
		v[0] = 1;
		v[1] = 2;
		v[2] = 4;
		int mod = 1000000007;
		for (int i = 3; i < n; ++i)
		{
			v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % mod;
		}
		return v[n - 1];
	}
};