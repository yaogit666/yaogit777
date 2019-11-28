#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string BigToSmall(string &n)
{
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
		{
			n[i] += 32;
		}
	}
	return n;
}
int same(string &A, string &B)
{
	if (A.size() > B.size())
	{
		swap(A, B);
	}
	int count = 0;
	string same = "";
	string C = "";
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i; j < A.size(); j++)
		{
			C = A.substr(i, j - i + 1);
			if ((int)B.find(C) < 0)
			{
				break;
			}
			if (same.size() < C.size())
			{
				same = C;
				count = same.size();
			}
		}
	}
	return count;
}
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		BigToSmall(A);
		BigToSmall(B);
		cout << same(A, B) << endl;
	}
	system("pause");
	return 0;
}