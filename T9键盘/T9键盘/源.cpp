class Solution {
public:
	vector<string> getValidT9Words(string num, vector<string>& words) {
		vector<string> res;
		if (num.size() == 0 || words.size() == 0)
			return res;
		char T9[26] = { '2', '2', '2',
						'3', '3', '3',
						'4', '4', '4',
						'5', '5', '5',
						'6', '6', '6',
						'7', '7', '7','7',
						'8', '8', '8',
						'9', '9', '9', '9' };
		for (string word : words)
		{
			bool b = true;
			for (int i = 0; i < word.size(); i++)
			{
				if (T9[word[i] - 'a'] != num[i])
					b = false;
				if (!b)
					break;
			}
			if (b)
				res.push_back(word);
		}
		return res;
	}
};