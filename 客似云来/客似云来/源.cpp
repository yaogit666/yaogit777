#include<iostream>
#include<vector>
using namespace std;
long sum(int from, int to)
{
	vector<long> v(to, 0);
	v[0] = v[1] = 1;
	for (int i = 2; i < to; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}
	long res = 0;
	for (int i = from - 1; i < to; i++)
	{
		res += v[i];
	}
	return res;
}
int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		cout << sum(from, to) << endl;
	}
	return 0;
}