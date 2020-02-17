#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v1;
	vector<int> v2;
	int n1;
	int n2;
	while (cin >> n1)
	{
		v1.push_back(n1);
		if (cin.get() == '\n')
			break;
	}
	while (cin >> n2)
	{
		v2.push_back(n2);
		if (cin.get() == '\n')
			break;
	}
	int count = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0, j = 0; i < v1.size() && j < v2.size(); j++)
	{
		if (v1[i] <= v2[j])
		{
			i++;
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}