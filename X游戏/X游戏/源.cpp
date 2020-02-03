#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	string s0 = "2569";
	string s1 = "347";
	for (int i = 2; i <= n; i++)
	{
		stringstream ss;
		ss << i;
		string str;
		ss >> str;
		if (str.find_first_of(s1) == str.npos && str.find_first_of(s0) != str.npos)
			count++;
	}

	cout << count << endl;
	system("pause");
	return 0;
}