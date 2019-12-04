#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int n = 0;
		for (auto &i : s)
		{
			n += i - '0';
		}
		while (n >= 10)
		{
			int ret = 0;
			while (n > 0)
			{
				ret += n % 10;
				n /= 10;
			}
			n = ret;
		}
		cout << n << endl;
	}
	return 0;
}