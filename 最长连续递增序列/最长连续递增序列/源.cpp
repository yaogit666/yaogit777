class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int count = 1;
		int maxC = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] < nums[i])
			{
				count++;
				maxC = max(count, maxC);
			}
			else
				count = 1;
		}
		return maxC;
	}
};