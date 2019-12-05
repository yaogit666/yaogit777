#include<iostream>
using namespace std;
bool IsCd(double cat, double length)
{
	if (2 * length*3.14 < cat)
	{
		return false;
	}
	return true;
}
int main()
{
	double cat;
	double length;
	while (cin >> cat >> length)
	{
		if(IsCd(cat, length))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}