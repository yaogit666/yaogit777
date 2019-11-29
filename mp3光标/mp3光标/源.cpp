#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n ;
	string s;
	while (cin >> n >> s)
	{
		int k = 1;
		if (n <= 4)
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (k == 1)
					{
						k = n;
					}
					else
						k--;
				}
				else if (s[i] == 'D')
				{
					if (k == n)
					{
						k = 1;
					}
					else
						k++;
				}
			}
			for (int i = 1; i < n; i++)
				cout << i << ' ';
			cout << n << endl;
			cout << k << endl;
		}
		else
		{
			int frist = k;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (frist == 1 && k == 1)
					{
						k = n;
						frist = n - 3;
					}
					else if (frist == k && k !=1)
					{
						k--;
						frist--;
					}
					else
						k--;
				}
				else if (s[i] == 'D')
				{
					if (frist == k -3 && k == n)
					{
						k = 1;
						frist = 1;
					}
					else if (frist == k - 3 && k != n)
					{
						frist++;
						k++;
					}
					else
						k++;
				}
			}
			for (int i = frist; i < frist+3; i++)
				cout << i << ' ';
			cout << frist + 3 << endl;
			cout << k << endl;
		}
	}
	system("pause");
	return 0;
}