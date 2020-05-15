class Solution {
public:
	bool buddyStrings(string A, string B) {
		if ((A.size() != B.size()) || (A.empty() && B.empty()))
			return false;
		int count = 0;
		string sA;
		string sB;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] != B[i])
			{
				count++;
				sA += A[i];
				sB += B[i];
			}
		}
		if (count == 2)
		{
			if (sA[0] == sB[1] && sA[1] == sB[0])
				return true;
			else
				return false;
		}
		else if (count == 0)
		{
			vector<int> v(26, 0);
			for (int i = 0; i < A.size(); i++)
			{
				v[A[i] - 'a']++;
			}
			for (int i = 0; i < 26; i++)
			{
				if (v[i] > 1)
					return true;
			}
			return false;
		}
		else
			return false;
	}
};