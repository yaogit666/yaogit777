class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> v;
		func(v, nums, 0);
		return v;
	}

	void func(vector<vector<int>>&v, vector<int>&nums, int n)
	{
		if (n == nums.size())
		{
			v.push_back(nums);
		}
		else
		{
			for (int i = n; i < nums.size(); i++)
			{
				swap(nums[i], nums[n]);
				func(v, nums, n + 1);
				swap(nums[i], nums[n]);
			}
		}
	}
};