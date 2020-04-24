class Solution {
public:
	string replaceSpaces(string S, int length) {
		string s;
		for (int i = 0; i < length; ++i)
		{
			if (S[i] == ' ')
			{
				s += "%20";
			}
			else
			{
				s += S[i];
			}
		}
		return s;
	}
};