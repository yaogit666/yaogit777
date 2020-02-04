#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int pos = s.find(';');
	string a;
	string b;
	a = s.substr(0, pos);
	b = s.substr(pos + 1);
	int length = a.size();
	bool flag = false;
	for (int i = 0; i <= length / 2; i++)
	{
		string left = a.substr(0, i);
		string right = a.substr(i);
		string c = right + left;
		if (b == c)
			flag = true;
	}
	if (flag)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}