class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<int>> map;
		for (int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			map[s].push_back(i);
		}
		for (auto it : map)
		{
			auto v = it.second;
			vector<string> ve;
			for (auto i : v)
			{
				ve.push_back(strs[i]);
			}
			res.push_back(ve);
		}
		return res;
	}
};