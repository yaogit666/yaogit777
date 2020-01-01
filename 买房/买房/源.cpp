#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << '0' << ' ';
		if (n < 3 || k < 2)
			cout << '0' << endl;
		else
			cout << min(n - k, k - 1) << endl;
	}
	return 0;
}