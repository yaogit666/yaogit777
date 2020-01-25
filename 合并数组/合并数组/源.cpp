#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	string s1;
	string s2;
	cin >> s1 >> s2;
	stringstream ss1(s1);
	char c;
	int a;
	while (ss1 >> a)
	{
		v.push_back(a);
		if (ss1 >> c)
			continue;
	}
	stringstream ss2(s2);
	while (ss2 >> a)
	{
		v.push_back(a);
		if (ss2 >> c)
			continue;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << ',';
	}
	cout << v[v.size() - 1] << endl;
	return 0;
}