#include<iostream>
#include<string>
using namespace std;

void Reverse(string& s, int left, int right)
{
	while (left < right)
	{
		swap(s[left++], s[right--]);
	}
}

	string ReverseSentence(string& str) {
		if (str.find(' ') == str.npos)
			return str;
		string ss;
		int len = str.length();
		Reverse(str, 0, len - 1);
		int pos = str.find(' ');
		string s1 = str.substr(0, pos);
		Reverse(s1, 0, s1.size() - 1);
		ss += s1;
		ss += ' ';
		int j = pos + 1;
		for (int i = j; i < len; i++)
		{
			if (str[i] == ' ')
			{
				string s = str.substr(j, i - j + 1);
				Reverse(s, 0, s.size() - 2);
				ss += s;
				j = i + 1;
			}
		}
		string s2 = str.substr(j, len - j);
		Reverse(s2, 0, s2.size() - 1);
		ss += s2;
		return  ss;
	}


	
	int main()
	{
		string str;
		getline(cin, str);
		cout << ReverseSentence(str) << endl;
		system("pause");
		return 0;
	}