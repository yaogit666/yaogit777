#include<iostream>
using namespace std;
int main()
{
	int n = 1024;
	int x;
	int count=0;
	cin >> x;
	n = n - x;
	count += n / 64;
	n = n % 64;
	count += n / 16;
	n = n % 16;
	count += n / 4;
	n = n % 4;
	count += n;
	cout << count << endl;
	system("pause");
	return 0;
}