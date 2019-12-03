#include<iostream>
#include<vector>
using namespace std;

int getMost(vector<vector<int> > board)
{
	int length = board.size();
	int wideth = board[0].size();
	vector<vector<int>> v(length, vector<int>(wideth, 0));
	v[0][0] = board[0][0];
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < wideth; j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				v[i][j] = board[i][j] + v[i][j - 1];
			else if (j == 0)
				v[i][j] = board[i][j] + v[i - 1][j];
			else
			{
				if (v[i][j - 1] > v[i - 1][j])
				{
					v[i][j] = board[i][j] + v[i][j - 1];
				}
				else
				{
					v[i][j] = board[i][j] + v[i - 1][j];
				}
			}
		}
		return v[length - 1][wideth - 1];
	}
}

