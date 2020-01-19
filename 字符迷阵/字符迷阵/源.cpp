#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		vector<string> v(x);
		for (int i = 0; i < x; i++)
		{
			string s;
			cin >> s;
			v[i] = s;
		}
		string key;
		cin >> key;
		int len = key.size();

		int count = 0;

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (v[i][j] == key[0])
				{
					for (int n = 1; n < len; n++)
					{
						if (j + n >= y)
							break;
						if (v[i][j + n] != key[n])
							break;
						if (n == len - 1)
							count++;
					}
					for (int n = 1; n < len; n++)
					{
						if (i + n >= x)
							break;
						if (v[i + n][j] != key[n])
							break;
						if (n == len - 1)
							count++;
					}
					for (int n = 1; n < len; n++)
					{
						if (i + n >= x || j + n >= y)
							break;
						if (v[i + n][j + n] != key[n])
							break;
						if (n == len - 1)
							count++;
					}
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}