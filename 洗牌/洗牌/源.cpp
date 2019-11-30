#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int>table(num);
		for (int i = 0; i < num; i++)
		{
			cin >> table[i];
		}
		while (k--)
		{
			vector<int>tab(table.begin(), table.end());
			for (int i = 0; i < n; i++)
			{
				table[i * 2] = tab[i];
				table[i * 2 + 1] = tab[i + n];
			}
		}
		for (int j = 0; j < num - 1; j++)
		{
			cout << table[j] << " ";
		}
		cout << table[num - 1] << endl;
	}
	return 0;
}