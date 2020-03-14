class Solution {
public:
	int massage(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		vector<int> v(nums.size() + 1, 0);
		v[0] = nums[0];
		v[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			v[i] = max(v[i - 1], v[i - 2] + nums[i]);
		}
		return v[nums.size() - 1];
	}
};