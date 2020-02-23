class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<bool> v(rooms.size(), false);
		openRoom(v, rooms, rooms[0]);
		for (int i = 1; i < v.size(); i++)
		{
			if (!v[i])
				return false;
		}
		return true;
	}

	void openRoom(vector<bool>& v, vector<vector<int>>& rooms, vector<int>& vv)
	{
		vector<int> vvv;
		for (int i = 0; i < vv.size(); i++)
		{
			if (!v[vv[i]])
			{
				v[vv[i]] = true;
				for (int j = 0; j < rooms[vv[i]].size(); j++)
				{
					vvv.push_back(rooms[vv[i]][j]);
				}
				openRoom(v, rooms, vvv);
			}
		}
	}
};
