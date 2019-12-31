#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = x * 60 + y;
	}
	int timeToSchool;
	cin >> timeToSchool;
	int class1, class2;
	cin >> class1 >> class2;
	int classTime = class1 * 60 + class2;
	int maxTime = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] + timeToSchool <= classTime)
		{
			if (v[i] > maxTime)
			{
				maxTime = v[i];
			}
		}
	}
	cout << maxTime / 60 << ' ' << maxTime % 60 << endl;
	return 0;
}