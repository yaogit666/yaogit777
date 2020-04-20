class Solution {
public:
	bool oneEditAway(string first, string second) {
		int len1 = first.size();
		int len2 = second.size();
		int i = 0;
		int j = 0;
		int res = 0;
		if (abs(len1 - len2) > 1)
			return false;
		while (i < len1 && j < len2)
		{
			if (first[i] == second[j])
			{
				++i;
				++j;
				continue;
			}
			else
			{
				if (j < len2 - 1)
				{
					if (first[i] == second[j + 1])
					{
						++j;
						++res;
						continue;
					}
				}
				if (i < len1 - 1)
				{
					if (first[i + 1] == second[j])
					{
						++i;
						++res;
						continue;
					}
				}
				++i;
				++j;
				++res;
			}
			if (res > 1)
				return false;
		}
		if ((len1 - i) + (len2 - j) + res > 1)
			return false;
		else
			return true;
	}
};