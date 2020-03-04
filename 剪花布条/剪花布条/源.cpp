#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string ss;
	while (cin >> s >> ss)
	{
		int count = 0;
		int lenth = ss.length();
		bool b = false;
		for (int i = 0; i < s.size();)
		{
			for (int j = 0; j < lenth; j++)
			{
				if (s[i + j] != ss[j])
				{
					break;
				}
				else if (j == lenth - 1)
				{
					b = true;
				}
			}
			if (b == true)
			{
				count += 1;
				b = false;
				i += lenth;
			}
			else
			{
				i += 1;
			}
		}
		cout << count << endl;
	}
	return 0;
}