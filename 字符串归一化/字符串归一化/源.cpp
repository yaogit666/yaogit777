#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		sort(s.begin(), s.end());
		string str;
		int a = 1;
		cout << s[0];
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1])
			{
				++a;
			}
			else
			{
				cout << a;
				cout << s[i];
				a = 1;
			}
		}
		cout << a << endl;
		system("pause");
		return 0;
	}
}