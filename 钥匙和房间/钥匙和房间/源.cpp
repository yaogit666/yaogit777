class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<bool>v(rooms.size(), false);////房间访问记录数组
		dfs(rooms, rooms[0], v);
		v[0] = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (!v[i])
				return false;
		}
		return true;
	}
	void dfs(vector<vector<int>>& rooms, vector<int> &vec, vector<bool>&v)
	{

		vector<int> vec1;
		for (int i = 0; i < vec.size(); i++)
		{
			if (!v[vec[i]])////剪枝避免重复访问
			{
				v[vec[i]] = true;
				for (int j = 0; j < rooms[vec[i]].size(); j++)////得到下一个房间的钥匙
				{
					vec1.push_back(rooms[vec[i]][j]);
					dfs(rooms, vec1, v);
				}
			}

		}

	}
};
