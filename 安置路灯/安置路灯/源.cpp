#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		string s;
		cin >> x;
		cin >> s;
		int count=0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '.')
			{
				i += 2;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}