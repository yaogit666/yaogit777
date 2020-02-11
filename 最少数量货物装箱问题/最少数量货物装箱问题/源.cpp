#include<iostream>
using namespace std;
int main()
{
	int x;
	cin >> x;
	if (x == 1 || x == 2 || x == 4)
		cout << -1 << endl;
	else
	{
		int count = 0;
		count += x / 7;
		x = x % 7;
		if (x == 3 || x == 5 || x == 1)
			count += 1;
		if (x == 2 || x == 4 || x == 6)
			count += 2;
		cout << count << endl;
	}
	return 0;
}