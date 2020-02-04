#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	string b;
	while (cin >> a >> b)
	{
		if (a.find(b) != a.npos || b.find(a) != b.npos)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}