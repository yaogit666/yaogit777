#include<iostream>
#include<string>
using namespace std;

bool compare(string &A, string&B)
{
	for (int i = 0, j = 0; i < A.size() && j < B.size(); )
	{
		if (A[i] == B[j])
		{
			i++;
			j++;
		}
		else
		{
			if (A[i] == '*')
			{
				if (i == A.size() - 1)
				{
					return true;
				}
				else
				{
					while (A[i + 1] != B[j])
					{
						if (j == B.size() - 1)
						{
							return false;
						}
						j++;
					}
				}
			}
			else if (A[i] == '?')
			{
				i++;
				j++;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	string A;
	string B;
	while (cin >> A >> B)
	{
		if (compare(A, B))
		{
			cout << "true" << endl;
		}
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}