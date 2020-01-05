#include<iostream>
using namespace std;
int main()
{
	int N;
	int n = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		n = n + i;
	}
	n = n + 1 + N;
	cout << n << endl;
	system("pause");
	return 0;
}