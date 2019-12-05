#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSum(vector<int> &v)
{
	int maxsum = v[0];
	int sum = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		sum = (sum > 0) ? v[i] + sum : v[i];
		maxsum = (maxsum > sum) ? maxsum : sum;
	}
	return maxsum;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < v.size(); i++)
		{
			cin >> v[i];
		}
		cout << maxSum(v) << endl;
	}
	return 0;
}