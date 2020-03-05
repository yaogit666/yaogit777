#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		cin.get();
		vector<string> v;
		while (n--)
		{
			string s = "";
			getline(cin, s);
			if (s.find(',') != s.npos || s.find(' ') != s.npos)
			{
				string ss = "";
				ss += '\"';
				ss += s;
				ss += '\"';
				v.push_back(ss);
			}
			else
			{
				v.push_back(s);
			}
		}
		int len = v.size();
		for (int i = 0; i < len - 1; i++)
		{
			cout << v[i] << ", ";
		}
		cout << v[len - 1] << endl;
	}
	return 0;
}