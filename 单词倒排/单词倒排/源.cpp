#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	if (s.find(' ') == s.npos)
		cout << s << endl;
	vector<string> v;
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			string str = s.substr(j, i - j);
			v.push_back(str);
			j = i + 1;
		}
	}
	v.push_back(s.substr(j, s.size() - j));
	for (int i = v.size()-1; i > 0; i--)
	{
		cout << v[i] << ' ';
	}
	cout << v[0] << endl;
	system("pause");
	return 0;
}