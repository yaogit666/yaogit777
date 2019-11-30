#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s.find(s[i]) == s.rfind(s[i]))
			{
				cout << s[i] << endl;
				break;
			}
			if (i == s.size() - 1)
			{
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}