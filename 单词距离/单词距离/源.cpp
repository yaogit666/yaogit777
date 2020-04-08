class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		int t1 = -1;
		int t2 = -1;
		int res = INT_MAX;
		for (int i = 0; i < words.size(); i++)
		{
			if (words[i] == word1)
				t1 = i;
			if (words[i] == word2)
				t2 = i;
			if (t1 != -1 && t2 != -1)
				res = min(res, abs(t2 - t1));
		}
		return res;
	}
};