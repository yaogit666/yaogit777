#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	string s;
	cin >> N;
	while (N)
	{
		if (N % 2 == 0)
		{
			N = (N - 2) / 2;
			s.push_back('3');
		}
		else
		{
			N = (N - 1) / 2;
			s.push_back('2');
		}
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		cout << s[i];
	}
	return 0;
}