#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int GetUglyNumber_Solution(int index) {
	if (index < 7)
		return index;
	int p2 = 0, p3 = 0, p5 = 0;
	vector<int> v;
	int n = 1;
	v.push_back(n);
	while (v.size() < index)
	{
		n = min(v[p2] * 2, min(v[p3] * 3, v[p5] * 5));
		if (v[p2] * 2 == n)
			p2++;
		if (v[p3] * 3 == n)
			p3++;
		if (v[p5] * 5 == n)
			p5++;
		v.push_back(n);
	}
	return n;
}

int main()
{
	int n;
	cin >> n;
	cout << GetUglyNumber_Solution(n) << endl;
	system("pause");
	return 0;
}