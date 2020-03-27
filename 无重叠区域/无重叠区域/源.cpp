class Solution {
public:
	static bool cmp(vector<int>& v1, vector<int>& v2)
	{
		return v1[1] < v2[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return 0;
		int len = intervals.size();
		sort(intervals.begin(), intervals.end(), cmp);
		int count = 1;
		int first_end = intervals[0][1];
		for (int i = 1; i < len; i++)
		{
			if (intervals[i][0] >= first_end)
			{
				count++;
				first_end = intervals[i][1];
			}
		}
		return len - count;
	}
};