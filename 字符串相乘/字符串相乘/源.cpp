#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	stringstream ss1(s1);
	stringstream ss2(s2);
	int a, b;
	ss1 >> a;
	ss2 >> b;
	int n = a * b;
	cout << n << endl;
	return 0;
}