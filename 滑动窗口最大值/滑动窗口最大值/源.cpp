class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		int len = num.size();
		vector<int> result;
		if (len < size || size == 0)
			return result;

		for (int i = 0; i <= len - size; i++)
		{
			int max = num[i];
			for (int j = i; j < i + size; j++)
			{
				if (num[j] > max)
					max = num[j];
			}
			result.push_back(max);
		}
		return result;
	}
};