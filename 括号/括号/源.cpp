class Solution {
public:
	vector<string> v;
	vector<string> generateParenthesis(int n)
	{
		push("", 0, 0, n);
		return v;
	}

	void push(string s, int left, int right, int n)
	{
		if (s.length() == 2 * n)
		{
			v.push_back(s);
			return;
		}
		if (left < n)
		{
			push(s + "(", left + 1, right, n);
		}
		if (right < left)
		{
			push(s + ")", left, right + 1, n);
		}
	}
};