#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string A = "";
	string B = "";
	while (cin >> A >> B)
	{
		string max = "";
		if (A.size() > B.size())
		{
			swap(A, B);
		}
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = i; j < A.size(); j++)
			{
				string s = A.substr(i, j - i + 1);

				if ((int)B.find(s) < 0)
				{
					break;
				}
				if (max.size() < s.size())
				{
					swap(max, s);
				}
			}
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}