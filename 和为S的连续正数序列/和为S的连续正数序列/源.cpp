#include<iostream>
#include<vector>
using namespace std;
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> v;
		if (sum < 3)
			return v;
		int begin = 1;
		int end = 2;
		int s = begin + end;
		while (begin < (sum + 1) / 2 && end < sum)
		{
			while (s > sum)
			{
				s -= begin;
				begin++;
			}
			if (s == sum)
			{
				vector<int> vv;
				for (int i = begin; i <= end; i++)
				{
					vv.push_back(i);
				}
				v.push_back(vv);
			}
			end++;
			s += end;
		}
		return v;
	}

	int main()
	{
		int n;
		cin >> n;
		vector<vector<int>> v = FindContinuousSequence(n);
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j] << ' ';
			}
			cout << endl;
		}
		system("pause");
		return 0;
	}