#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	while (n--)
	{
		int a;
		string s;
		cin >> s;
		stringstream ss(s.substr(s.size() - 6));
		ss >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}