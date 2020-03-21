class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<pair<int, int>> v(nums.size(), { 1,1 });
		int mx = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
				{
					if (v[i].first < v[j].first + 1)
					{
						v[i] = { v[j].first + 1, v[j].second };
					}
					else if (v[i].first == v[j].first + 1)
					{
						v[i].second += v[j].second;
					}
				}
			}
			mx = max(mx, v[i].first);
		}
		int res = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].first == mx)
				res += v[i].second;
		}
		return res;
	}
};