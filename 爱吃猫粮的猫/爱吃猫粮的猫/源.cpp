#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<int> v;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int H;
	cin >> H;

	int K = 1;
	while (1)
	{
		int time = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] % K == 0)
				time += v[i] / K;
			else
				time += v[i] / K + 1;
		}
		if (time <= H)
		{
			cout << K << endl;
			break;
		}
		else
			K++;
	}
	system("pause");
	return 0;
}