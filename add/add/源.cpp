#include<iostream>
using namespace std;
int Add(int num1, int num2)
{

	while(num2)
	{
		int ret = num1 ^ num2;
		num2 = (num1 & num2) << 1;
		num1 = ret;
		
	}
	return num1;
}

int main()
{
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		cout << Add(num1, num2) << endl;
	}
}