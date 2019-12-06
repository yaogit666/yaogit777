class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;

		vector<bool> table(s.size() + 1, false);
		table[0] = true;

		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (table[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					table[i] = true;
					break;
				}
			}
		}
		return table[s.size()];
	}
};