#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int n = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i - 1] == s[i])
			n++;
		else
		{
			if (n > 0)
				cout << n << s[i - 1];
			else
				cout << s[i - 1];
			n = 0;
		}
	}
	if (n > 0)
		cout << n << s[s.size() - 1];
	else
		cout << s[s.size() - 1];
	system("pause");
	return 0;
}