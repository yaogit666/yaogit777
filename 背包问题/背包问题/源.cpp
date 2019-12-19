#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int backPackII(int m, vector<int> &A, vector<int> &V) {
	if (A.empty() || V.empty() || m < 0)
	{
		return 0;
	}
	else
	{
		int M = A.size() + 1;
		int N = m + 1;
		vector<vector<int>> result(M, vector<int>(N, 0));

		for (int i = 1; i < M; i++)
		{
			for (int j = 1; j < N; j++)
			{
				if (A[i - 1] > j)
				{
					result[i][j] = result[i - 1][j];
				}
				else
				{
					int num = result[i - 1][j - A[i - 1]] + V[i - 1];
					result[i][j] = max(num, result[i - 1][j]);
				}
			}
		}
		return result[M - 1][m];
	}
}

int main()
{
	int m = 10;
	vector<int>A(4, 0);
	vector<int>V(4, 0);
	for (int i = 0; i < 4; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> V[i];
	}
	cout << backPackII(m, A, V);
	system("pause");
}
