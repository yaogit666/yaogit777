class Solution {
public:
	vector<vector<int>> res;
	vector<int> v;
	vector<vector<int>> subsets(vector<int>& nums) {
		res.push_back(v);
		subsetsPush(nums, 0);
		return res;
	}

	void subsetsPush(vector<int>nums, int n)
	{
		if (n >= nums.size())
			return;
		for (int i = n; i < nums.size(); i++)
		{
			v.push_back(nums[i]);
			res.push_back(v);
			subsetsPush(nums, i + 1);
			v.pop_back();
		}
	}
};