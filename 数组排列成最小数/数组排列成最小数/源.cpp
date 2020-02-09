#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int stringToInt(string s)
{
	int a;
	stringstream ss(s);
	ss >> a;
	return a;
}
string intToString(int a)
{
	string s;
	stringstream ss;
	ss << a;
	ss >> s;
	return s;
}
string SmallSum(int a, int b)
{
	string C = "";
	string A = intToString(a);
	string B = intToString(b);
	if (A + B > B + A)
	{
		C = B + A;
		return C;
	}
	else
	{
		C = A + B;
		return C;
	}
}

string PrintMinNumber(vector<int> numbers) 
{
	string s = intToString(numbers[0]);
	for (size_t i = 1; i < numbers.size(); i++)
	{
		int n = stringToInt(s);
		s = SmallSum(n, numbers[i]);

	}
	return s;
}

int main()
{
	int n;
	vector<int> v;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	cout << PrintMinNumber(v) << endl;
	system("pause");
	return 0;
}