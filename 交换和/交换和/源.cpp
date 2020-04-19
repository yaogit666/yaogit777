class Solution {
public:
	vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
		int sum1 = 0;
		int sum2 = 0;
		for (auto i : array1)
		{
			sum1 += i;
		}
		for (auto i : array2)
		{
			sum2 += i;
		}
		sort(array1.begin(), array1.end());
		sort(array2.begin(), array2.end());
		int i = 0;
		int j = 0;
		vector<int> v;
		while (i < array1.size() && j < array2.size())
		{
			int val1 = sum1 + 2 * array2[j];
			int val2 = sum2 + 2 * array1[i];
			if (val1 < val2)
			{
				++j;
			}
			else if (val1 > val2)
			{
				++i;
			}
			else
			{
				v.push_back(array1[i]);
				v.push_back(array2[j]);
				return v;
			}
		}
		return v;
	}
};