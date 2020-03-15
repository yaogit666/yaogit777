#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				cout << s[i];
			}
			else
				continue;
		}
		cout << endl;
	}
	return 0;
}