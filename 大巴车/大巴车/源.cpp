#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	vector<int> v(a);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	stack<vector<int>> s;
	vector<int> vv;
	for (int i = 0; i < v.size(); i++)
	{
		if (i % b == 0 && i != 0)
		{
			s.push(vv);
			vv.clear();
		}
		vv.push_back(v[i]);
	}
	if (vv.size() != 0)
	{
		for (int i = 0; i < vv.size(); i++)
		{
			cout << vv[i] << ' ';
		}
	}
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		vector<int> vvv;
		vvv = s.top();
		for (auto j : vvv)
		{
			cout << j << ' ';
		}
		s.pop();
	}
	system("pause");
	return 0;
}