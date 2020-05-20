class Solution {
public:
	int translateNum(int num) {
		if (num < 10) return 1;
		vector<int> nums;
		while (num) {
			nums.push_back(num % 10);
			num /= 10;
		}
		reverse(nums.begin(), nums.end());
		int ans = 0, num1 = 1, num2 = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] == 0 || nums[i - 1] * 10 + nums[i] > 25) {
				ans = num1;
			}
			else {
				ans = num1 + num2;
			}
			num2 = num1;
			num1 = ans;
		}
		return ans;
	}
};