#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		s.resize(n);
		cin >> s;
		string str = "NESW";
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'L')
			{
				if (x == 0)
					x = 3;
				else
					x--;
			}
			else
			{
				if (x == 3)
					x = 0;
				else
					x++;
			}
		}
		cout << str[x] << endl;
	}
	return 0;
}