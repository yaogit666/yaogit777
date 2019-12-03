#include<iostream>
#include<vector>
using namespace std;

int length;
int wideth;
vector<vector<int>> v;
vector<vector<int>> bestWay;
vector<vector<int>> temp;

void GoWay(int i, int j)
{
	v[i][j] = 1;
	temp.push_back({ i,j });

	if (i == length - 1 && j == wideth - 1)
	{
		if (bestWay.empty() || temp.size() < bestWay.size())
		{
			bestWay = temp;
		}
	}

	if (i - 1 >= 0 && v[i - 1][j] == 0)
		GoWay(i - 1, j);
	if (i + 1 < length && v[i + 1][j] == 0)
		GoWay(i + 1, j);
	if (j - 1 >= 0 && v[i][j - 1] == 0)
		GoWay(i, j - 1);
	if (j + 1 < wideth && v[i][j + 1] == 0)
		GoWay(i, j + 1);

	v[i][j] = 0;
	temp.pop_back();
}
int main()
{
	while (cin >> length >> wideth)
	{
		v = vector<vector<int>>(length, vector<int>(wideth, 0));
		bestWay.clear();
		temp.clear();
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < wideth; j++)
			{
				cin >> v[i][j];
			}
		}
		GoWay(0, 0);

		for (auto i : bestWay)
		{
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
		}
	}
	return 0;
}