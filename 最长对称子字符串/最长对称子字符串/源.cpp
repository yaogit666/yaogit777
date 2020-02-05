#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool Symmetric(string str)
{
	int right = str.size() - 1;
	int left = 0;
	while (left < right)
	{
		if (str[left] == str[right])
		{
			left++;
			right--;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	string s;
	cin >> s;
	int maxL = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = s.size() - i; j > i; j--)
		{
			string ss = s.substr(i, j);
			if (Symmetric(ss))
			{
				maxL = max(maxL, (int)ss.size());
			}
		}
	}
	for (int i = 0; i <= s.size() - maxL; i++)
	{
		string ss = s.substr(i, maxL);
		if (Symmetric(ss))
		{
			cout << ss << endl;
		}
	}
	system("pause");
	return 0;
}