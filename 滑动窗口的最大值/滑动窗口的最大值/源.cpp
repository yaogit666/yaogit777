class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> v;
		int left = 0;
		int right = k - 1;
		while (right < nums.size())
		{
			int temp = INT_MIN;
			for (int i = left; i <= right; i++)
			{
				temp = max(temp, nums[i]);
			}
			v.push_back(temp);
			left++;
			right++;
		}
		return v;
	}
};