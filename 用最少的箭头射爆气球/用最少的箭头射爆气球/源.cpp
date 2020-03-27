class Solution {
public:
	static bool cmp(vector<int>& v1, vector<int>& v2)
	{
		return v1[1] < v2[1];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty())
			return 0;
		sort(points.begin(), points.end(), cmp);
		int count = 1;
		int first_end = points[0][1];
		for (int i = 1; i < points.size(); i++)
		{
			if (points[i][0] > first_end)
			{
				count++;
				first_end = points[i][1];
			}
		}
		return count;
	}
};