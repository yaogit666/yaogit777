#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	int sum = 0;
	cin >> n >> k;
	vector<int> v1;
	vector<int> v2;
	v1.resize(n);
	v2.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v2[i];
		if (v2[i])
			sum += v1[i];
	}
	int maxN = 0;
	for (int i = 0; i <= n - k; i++)
	{
		int N = 0;
		for (int j = 0; j < k; j++)
		{
			if (v2[i + j] == 0)
				N += v1[i + j];
			maxN = max(maxN, N);
		}
	}
	cout << maxN + sum << endl;
	return 0;
}