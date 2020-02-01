#include<iostream>
using namespace std;
int main()
{
	int v[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
	int Y, M, D;
	cin >> Y >> M >> D;
	if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
		cout << v[M - 1] + D + 1 << endl;
	else
		cout << v[M - 1] + D << endl;
	return 0;
}