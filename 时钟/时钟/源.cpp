#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if ((s[0] - '0')*10 + (s[1] - '0') > 23)
			s[0] = '0';
		if ((s[3] - '0')*10 + (s[4] - '0') > 59)
			s[3] = '0';
		if ((s[6] - '0')*10 + (s[7] - '0') > 59)
			s[6] = '0';
		cout << s << endl;
	}
	return 0;
}