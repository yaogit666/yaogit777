#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v;
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}
	vector<int>vv;
	vv.resize(n);
	int min = 0;
	for (int i = 1; i <= n; i++)
	{
		vv[i - 1] = count(v.begin(), v.end(), i);
	}
	int minX = *min_element(vv.begin(), vv.end());
	cout << minX << endl;
	system("pause");
	return 0;
}