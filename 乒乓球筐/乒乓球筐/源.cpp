#include<iostream>
#include<string>
using namespace std;
int main()
{
	string A;
	string B;
	bool b = false;
	while (cin >> A >> B)
	{
		for (int i = 0; i < B.size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				if (A[j] == B[i])
				{
					A.erase(j, 1);
					break;
				}
				if (j == A.size() - 1)
					b = true;
			}
		}
		if (b)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}