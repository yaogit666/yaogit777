#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<long> v(n + 1, 0);
		v[0] = v[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			v[i] = v[i - 1] + v[i - 2];
		}
		cout << v[n] << endl;
	}
	return 0;
}