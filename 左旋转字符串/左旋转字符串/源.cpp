class Solution {
public:
	string LeftRotateString(string str, int n) {
		string s1;
		string s2;
		for (int i = 0; i < n; i++)
		{
			s1 += str[i];
		}
		for (int i = n; i < str.size(); i++)
		{
			s2 += str[i];
		}
		s2 += s1;
		return s2;
	}
};