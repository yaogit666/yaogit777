class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() < 3 || nums.empty())
			return;

		bool b = nums[0] > nums[1];
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (b && nums[i] < nums[i + 1])
				swap(nums[i], nums[i + 1]);
			else if (!b && nums[i] > nums[i + 1])
				swap(nums[i], nums[i + 1]);
			b = !b;
		}
	}
};