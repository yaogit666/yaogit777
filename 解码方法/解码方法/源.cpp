#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int> v(s.size() + 1, 0);
	v[0] = 1;
	for (int i = 1; i <= s.size(); ++i)
	{
		if (s[i - 1] != '0')
			v[i] += v[i - 1];
		if (i >= 2 && s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7')
			v[i] += v[i - 2];
	}
	cout << v[s.size()] << endl;
	return 0;
}