//桌子上放了红包  1, 2, 3, 4, 7, 10。
//小明在“4,7”之间、“7,10” 之间各切一刀，
//将红包分成3组 [1, 2, 3, 4]   [7]   [10]，
//其中第一组奖金之和=第三组奖金之和=10，所以小明可以拿到10越南盾。
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector <int> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int left = 0;
		long long sum_left = v[left];
		int right = n - 1;
		long long sum_right = v[right];
		long long sum = 0;
		while (left < right)
		{
			if (sum_left == sum_right)
			{
				sum = sum_left;
				left++;
				right--;
				sum_left += v[left];
				sum_right += v[right];
			}
			else if (sum_left < sum_right)
			{
				left++;
				sum_left += v[left];
			}
			else if (sum_left > sum_right)
			{
				right--;
				sum_right += v[right];
			}
		}
		cout << sum << endl;
	}
	return 0;
}