#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a%b == 0)
		cout << a / b;
	else
	{
		cout << a / b << '.';
		map<int, int> m;
		vector<int> v;
		a = a % b;
		int t = 0;
		while (a != 0)
		{
			if (m.count(a) != 0)
				break;
			else
			{
				v.push_back(a * 10 / b);
				m[a] = t++;
				a = a * 10 % b;
			}
		}
		if (a == 0)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			}
		}
		else
		{
			int k = m[a];
			for (int i = 0; i < k; i++)
			{
				cout << v[i];
			}
			cout << '(';
			for (int i = k; i < v.size(); i++)
			{
				cout << v[i];
			}
			cout << ')';
		}
	}
	cout << endl;
	return 0;
}