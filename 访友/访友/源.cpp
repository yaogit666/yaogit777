#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 5; i > 0; i--)
	{
		count += n / i;
		n = n % i;
		if (n == 0)
			break;
	}
	cout << count << endl;
	return 0;
}