class Solution {
public:
	string compressString(string S) {
		string s;
		if (S.empty())
			return s;
		int n = 1;
		for (int i = 1; i < S.size(); i++)
		{
			if (S[i] == S[i - 1])
				++n;
			else
			{
				s += S[i - 1];
				s += to_string(n);
				n = 1;
			}
		}
		if (n == 0)
			s += S[S.size() - 1];
		else
		{
			s += S[S.size() - 1];
			s += to_string(n);
		}

		if (s.size() < S.size())
			return s;
		else
			return S;
	}
};