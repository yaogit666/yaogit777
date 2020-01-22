#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int stat = 0;
	int end = n - 1;
	int maxN = v[stat] + v[end];
	int minN = v[stat] + v[end];
	while (stat < end)
	{
		maxN = max(v[stat] + v[end], maxN);
		minN = min(v[stat] + v[end], minN);
		stat++;
		end--;
	}
	cout << maxN - minN << endl;
	system("pause");
	return 0;
}