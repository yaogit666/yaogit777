//1

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		if (triangle.empty())
		{
			return 0;
		}

		vector<vector<int>> v(triangle);

		int length = v.size();

		for (int i = 1; i < length; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
				{
					v[i][j] = v[i - 1][j];
				}
				else if (j == i)
				{
					v[i][j] = v[i - 1][j - 1];
				}
				else
				{
					v[i][j] = min(v[i - 1][j - 1], v[i - 1][j]);
				}
				v[i][j] += triangle[i][j];
			}
		}

		int minnum = v[length - 1][0];
		for (int i = 0; i < length; i++)
		{
			minnum = min(minnum, v[length - 1][i]);
		}
		return minnum;
	}
};

//2

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		if (triangle.empty())
		{
			return 0;
		}

		vector<vector<int>> v(triangle);

		int length = v.size();

		for (int i = length - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				v[i][j] = min(v[i][j] + v[i + 1][j], v[i][j] + v[i + 1][j + 1]);
			}
		}
		return v[0][0];
	}
};