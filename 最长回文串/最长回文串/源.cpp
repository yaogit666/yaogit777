class Solution {
public:
	int longestPalindrome(string s) {
		vector<int> hashTable(54, 0);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				hashTable[s[i] - 'a' + 26]++;
			else
				hashTable[s[i] - 'A']++;
		}
		int count = 0;
		bool b = false;
		for (int i = 0; i < 54; i++)
		{
			if (hashTable[i] % 2 != 0)
			{
				b = true;
				count += hashTable[i] - 1;
			}
			else
			{
				count += hashTable[i];
			}
		}
		if (b)
			count += 1;
		return count;
	}
};