#include<iostream>
#include<math.h>
using namespace std;
bool IsNumber(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
				if (IsNumber(i))
					count++;
		}
		cout << count << endl;
	}
	return 0;
}