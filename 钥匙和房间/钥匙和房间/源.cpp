class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<bool>v(rooms.size(), false);////������ʼ�¼����
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
			if (!v[vec[i]])////��֦�����ظ�����
			{
				v[vec[i]] = true;
				for (int j = 0; j < rooms[vec[i]].size(); j++)////�õ���һ�������Կ��
				{
					vec1.push_back(rooms[vec[i]][j]);
					dfs(rooms, vec1, v);
				}
			}

		}

	}
};
