class Solution {
public:
	vector<int> pondSizes(vector<vector<int>>& land) {
		vector<int> v;
		for (int i = 0; i < land.size(); i++)
		{
			for (int j = 0; j < land[i].size(); j++)
			{
				int n = water(land, i, j);
				if (n != 0)
					v.push_back(n);
			}
		}
		return v;
	}

	int water(vector<vector<int>>& land, int i, int j)
	{
		if (i == land.size() || j == land[0].size() || i < 0 || j < 0)
			return 0;
		if (land[i][j] == 0)
		{
			land[i][j] = 1;
			return 1 + water(land, i + 1, j) + water(land, i, j + 1) + water(land, i - 1, j) + water(land, i, j - 1) + water(land, i + 1, j + 1) + water(land, i - 1, j - 1) + water(land, i + 1, j - 1) + water(land, i - 1, j + 1);
		}
		return 0;
	}
};