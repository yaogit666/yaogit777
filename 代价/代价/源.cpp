#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>v;
	v.resize(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[2] - v[0] << endl;
	return 0;
}