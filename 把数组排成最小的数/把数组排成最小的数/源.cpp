class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> v;
		string s;
		if (nums.empty())
			return s;
		for (int i = 0; i < nums.size(); i++)
		{
			stringstream sstream;
			string ss;
			sstream << nums[i];
			sstream >> ss;
			v.push_back(ss);
		}
		sort(v.begin(), v.end(), comp);
		for (int i = 0; i < v.size(); i++)
		{
			s += v[i];
		}
		return s;
	}

	static bool comp(string& s1, string& s2)
	{
		return (s1 + s2 < s2 + s1);
	}
};