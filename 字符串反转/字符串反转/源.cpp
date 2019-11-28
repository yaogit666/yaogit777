#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		string rs;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			rs += (s[i]);
		}
		cout << rs << endl;
	}
	system("pause");
	return 0;
}