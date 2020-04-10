class Solution {
public:
	bool isUnique(string astr) {
		vector<int> hashTable(26, 0);
		for (int i = 0; i < astr.size(); i++)
		{
			hashTable[astr[i] - 97]++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (hashTable[i] > 1)
				return false;
		}
		return true;
	}
};