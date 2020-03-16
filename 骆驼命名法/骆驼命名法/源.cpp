#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		string ss;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '_')
			{
				string str = s.substr(j, i-j);
				ss += str;
				s[i + 1] = s[i + 1] - 32;
				j = i+1;
			}
		}
		string str = s.substr(j, s.size() - j);
		ss += str;
		cout << ss << endl;
	}
	return 0;
}