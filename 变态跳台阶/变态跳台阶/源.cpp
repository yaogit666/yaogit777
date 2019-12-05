#include<iostream>
using namespace std;

int jumpFloorII(int number)
{
	int n = 0;
	if (number <= 0)
		return n = 0;
	else if (number == 1)
		return n = 1;
	else
		return 2 * jumpFloorII(number - 1);
}

int main()
{
	int number;
	cin>>number;
	cout << jumpFloorII(number) << endl;
	system("pause");
}
