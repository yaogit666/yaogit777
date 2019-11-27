#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 3)
		{
			cout << "0" << endl;
			break;
		}
		int a = 0;
		int b = 0;
		int ret = 0;
		while (n >= 3)
		{
			a = n / 3;
			b = n % 3;
			n = a + b;
			ret += a;
		}
		if (n == 2)
		{
			ret++;
		}
		cout << ret << endl;
	}
	system("pause");
	return 0;
}