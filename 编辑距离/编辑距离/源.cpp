#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int minDistance(string &s1, string &s2)
{
	int lenth = s1.size();
	int width = s2.size();
	vector<vector<int>> v(lenth+1, vector<int>(width+1,0));
	for (int i = 1; i <= lenth; i++)
	{
		v[i][0] = i;
	}
	for (int j = 1; j <= width; j++)
	{
		v[0][j] = j;
	}
	for (int i = 1; i <= lenth; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (s1[i-1] == s2[j-1])
				v[i][j] = v[i - 1][j - 1];
			else
			{
				v[i][j]=min(v[i - 1][j] + 1, min(v[i][j - 1] + 1, v[i - 1][j - 1] + 1));
			}
		}
	}
	return v[lenth][width];
}
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << minDistance(s1, s2) << endl;
	system("pause");
	return 0;
}