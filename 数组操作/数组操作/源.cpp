#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	vector<int> v0;
	vector<int> v1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 == 0)
			v0.push_back(v[i]);
		else
			v1.push_back(v[i]);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		v0.push_back(v1[i]);
	}
	for (int i = 0; i < v0.size() - 1; i++)
	{
		cout << v0[i] << ' ';
	}
	cout << v0[v0.size()-1] << endl;
	system("pause");
	return 0;
}