class Solution {
public:
	int smallestDifference(vector<int>& a, vector<int>& b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long mmin = INT_MAX;
		for (int i = 0, j = 0; i < a.size() && j < b.size();)
		{
			mmin = min(mmin, abs(long(a[i]) - long(b[j])));
			if (a[i] < b[j])
				i++;
			else
				j++;
		}
		return mmin;
	}
};