class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size())
		{
			return false;
		}
		else if (s1.empty() && s2.empty())
		{
			return true;
		}
		else
		{
			s1 += s1;
			for (int i = 0; i < s1.size();)
			{
				int j = 0;
				while (s1[i] == s2[j])
				{
					i++;
					j++;
					if (j == s2.size())
					{
						return true;
					}
				}
				i++;
				j = 0;
			}
			return false;
		}
	}
};