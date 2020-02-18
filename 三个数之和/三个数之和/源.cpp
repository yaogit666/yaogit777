class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> vv;
		if (nums.size() < 3)
			return vv;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				return vv;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				vector <int> v;
				if (nums[i] + nums[left] + nums[right] == 0)
				{
					v.push_back(nums[i]);
					v.push_back(nums[left]);
					v.push_back(nums[right]);
					vv.push_back(v);
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0)
					left++;
				else if (nums[i] + nums[left] + nums[right] > 0)
					right--;
			}
		}
		return vv;
	}
};