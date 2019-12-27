//�����Ϸ��˺��  1, 2, 3, 4, 7, 10��
//С���ڡ�4,7��֮�䡢��7,10�� ֮�����һ����
//������ֳ�3�� [1, 2, 3, 4]   [7]   [10]��
//���е�һ�齱��֮��=�����齱��֮��=10������С�������õ�10Խ�϶ܡ�
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