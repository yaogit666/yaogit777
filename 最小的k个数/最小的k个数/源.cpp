class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector <int> v;
		if (k > input.size())
			return v;
		else
		{
			sort(input.begin(), input.end());
			for (int i = 0; i < k; i++)
			{
				v.push_back(input[i]);
			}
			return v;
		}
	}
};