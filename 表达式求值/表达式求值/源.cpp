#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	if (v[0] == 1)
		cout << (v[0] + v[1])*v[2] << endl;
	else
		cout << v[0] * v[1] * v[2] << endl;
	system("pause");
	return 0;
}