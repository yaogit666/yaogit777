class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int min = 0;
		int fresh = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					fresh++;
				}
				else if (grid[i][j] == 2)
				{
					q.push({ i,j });
				}
			}
		}
		vector<pair<int, int>> v = { {-1,0},{1,0},{0,-1},{0,1} };
		while (!q.empty())
		{
			int n = q.size();
			bool b = false;
			for (int a = 0; a < n; a++)
			{
				auto x = q.front();
				q.pop();
				for (auto des : v)
				{
					int i = x.first + des.first;
					int j = x.second + des.second;
					if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
					{
						grid[i][j] = 2;
						q.push({ i,j });
						fresh--;
						b = true;
					}
				}
			}
			if (b)
			{
				min++;
			}
		}
		if (fresh)
			return -1;
		else
			return min;
	}
};