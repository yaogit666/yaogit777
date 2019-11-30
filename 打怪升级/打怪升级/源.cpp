#include<iostream>
#include<vector>
using namespace std;
int math(int a, int b)
{
	if (a > b)
	{
		int c = a;
		a = b;
		b = c;
	}
	for (int i = a; i > 0; i--)
	{
		if (b%i == 0 && a%i == 0)
		{
			return i;
			break;
		}
	}
}
int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (a >= v[i])
			{
				a += v[i];
			}
			else
			{
				a += math(v[i], a);
			}
		}
		cout << a << endl;
	}
	system("pasue");
	return 0;
}