#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	vector <int>v;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int maxx = v[0];
	if (v.size() != 1)
	{
		for (int i = 0; i < v.size(); i++)
		{
			int max0 = v[i];
			for (int j = i + 1; j < v.size() - 1; j++)
			{
				maxx = max(maxx, max0);
				max0 += v[j];
				if (max0 <= 0)
					break;
			}
		}
	}
	if (maxx <= 0)
		cout << 0 << endl;
	else
		cout << maxx << endl;
	system("pause");
	return 0;
}