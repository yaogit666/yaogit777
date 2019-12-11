#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s2 = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	string s;
	while (getline(cin, s))
	{
		vector<char> v;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				v.push_back(' ');
			}
			else
			{
				int pos = s1.find(s[i]);
				v.push_back(s2[pos]);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}