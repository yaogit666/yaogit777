class Solution {
public:
	vector<int> divingBoard(int shorter, int longer, int k) {
		vector<int> v;
		if (k <= 0)
			return v;
		if (shorter == longer)
		{
			v.push_back(shorter*k);
			return v;
		}
		int k1 = 0;
		while (k >= 0)
		{
			v.push_back(shorter*k + longer * k1);
			k1++;
			k--;
		}
		return v;
	}
};