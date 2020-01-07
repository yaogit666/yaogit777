#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	while (1)
	{
		int n;
		cin >> n;
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int limit;
	cin >> limit;
	sort(v.begin(), v.end());
	int left = 0;
	int right = v.size() - 1;
	int res = 0;
	while (left <= right)
	{
		if (v[left] + v[right] > limit)
		{
			right--;
			res++;
		}
		else
		{
			left++;
			right--;
			res++;
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}