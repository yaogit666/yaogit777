#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else if (n == 1)
			cout << "0" << endl;
		else if (n == 2 || n == 3)
			cout << "1" << endl;
		else
		{
			int count = 1;
			while (n > 3)
			{
				if (n % 3 == 0)
				{
					n /= 3;
				}
				else
				{
					n = n / 3 + 1;
				}
				count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}