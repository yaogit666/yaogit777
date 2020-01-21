#include<iostream>
#include<string>
using namespace std;
int main()
{
	int s1[26];
	string s2;
	for (int i = 0; i < 26; i++)
	{
		cin >> s1[i];
	}
	cin >> s2;
	int count = 1;
	int sum = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		sum += s1[s2[i] - 'a'];
		if (sum > 100)
		{
			count++;
			sum = s1[s2[i] - 'a'];
		}
	}
	cout << count << ' ' << sum << endl;
	return 0;
}