class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		if (len < 2)
			return 0;
		int i = 0;
		int j = len - 1;
		int maxWater = 0;
		while (i < j)
		{
			maxWater = max(maxWater, (j - i)*min(height[i], height[j]));
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return maxWater;
	}
};