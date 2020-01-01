#include<iostream>
#include<stack>
using namespace std;
int main()
{
	long x, y;
	cin >> x >> y;
	if (x == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		stack<int> s;
		while (x)
		{
			s.push(x%y);
			x = x / y;
		}
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
	return 0;
}