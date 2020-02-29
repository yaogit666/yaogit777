#include<iostream>
#include<vector>
using namespace std;
bool is24(vector<double> v, int sum, double n)
{
	if (v.empty())
		return n == sum;
	for (int i = 0; i < v.size(); i++)
	{
		vector<double> vv(v);
		vv.erase(vv.begin() + i);
		if (is24(vv, sum, n + v[i]) ||
			is24(vv, sum, n - v[i]) ||
			is24(vv, sum, n*v[i]) ||
			is24(vv, sum, n / v[i]))
			return true;
	}
	return false;
}
int main()
{
	vector<double> v(4);
	while (cin >> v[0] >> v[1] >> v[2] >> v[3])
	{
		if (is24(v, 24, 0))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}