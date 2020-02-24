#include<iostream>
using namespace std;
int arrangeCoins(int n) {
	int i = 0;
	while (n > 0)
	{
		i++;
		n = n - i;
	}
	if (n == 0)
		return i;
	else
		return i - 1;
}
	int main()
	{
		int n; 
		cin >> n;
		cout << arrangeCoins(n);
		system("pause");
		return 0;
	}