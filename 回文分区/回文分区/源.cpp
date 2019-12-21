class Solution {
public:
	int minCut(string s) {
		if (s.empty())
			return 0;
		vector<int> v(s.size(), 0);

		for (int i = 0; i < s.size(); ++i)
		{
			v[i] = i;
		}

		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (IsPal(s, 0, i))
				{
					v[i] = 0;
					break;
				}
				if (IsPal(s, j + 1, i))
				{
					v[i] = min(v[i], v[j] + 1);
				}
			}
		}
		return v[s.size() - 1];
	}
	bool IsPal(string s, int start, int end)
	{
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			++start;
			--end;
		}
		return true;
	}
};