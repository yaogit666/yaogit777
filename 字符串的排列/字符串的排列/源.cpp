class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> v;
		if (str.empty())
			return v;
		permutation(str, v, 0);
		sort(v.begin(), v.end());
		return v;
	}

	void permutation(string str, vector<string>&v, int begin)
	{
		if (begin == str.size() - 1)
		{
			if (find(v.begin(), v.end(), str) == v.end())
			{
				v.push_back(str);
			}
		}
		else
		{
			for (int i = begin; i < str.size(); ++i)
			{
				swap(str[i], str[begin]);
				permutation(str, v, begin + 1);
				swap(str[i], str[begin]);
			}
		}
	}

	void swap(char &frist, char &second)
	{
		int temp = frist;
		frist = second;
		second = temp;
	}
};