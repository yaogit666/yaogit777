class Solution {
public:
	vector<string> res;
	vector<string> permutation(string S) {
		if (S.empty())
			return res;
		string s;
		vector<int> v(S.size(), 0);
		sort(S.begin(), S.end());
		arrange(S, s, v);
		return res;
	}

	void arrange(string& S, string& s, vector<int>& v)
	{
		if (s.size() == S.size())
			res.push_back(s);
		for (int i = 0; i < S.size(); i++)
		{
			if (v[i] == 0)
			{
				if (i > 0 && S[i] == S[i - 1] && v[i - 1] == 1)
				{
					continue;
				}
				s += S[i];
				v[i] = 1;
				arrange(S, s, v);
				s.pop_back();
				v[i] = 0;
			}
		}
	}
};