#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, sum;
	while (cin >> n >> sum)
	{
		vector<long> v1(n + 1);
		for (int i = 1; i < v1.size(); i++)
		{
			cin >> v1[i];
		}
		vector<long>v2(sum + 1, 0);
		vector<vector<long>>vv(n + 1, vector<long>(sum + 1, 0));
		for (int i = 0; i < n + 1; i++)
		{
			vv[i][0] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= sum; j++)
			{
				if (j - v1[i] >= 0)
				{
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - v1[i]];
				}
				else
				{
					vv[i][j] = vv[i - 1][j];
				}
			}
		}
		cout << vv[n][sum] << endl;
	}
	return 0;
}