#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;

void arrange(vector<int> & nums, vector<int> & v, int n)
{
	if (v.size() > nums.size())
	{
		return;
	}
	else
	{
		res.push_back(v);
		for (int i = n; i < nums.size(); i++)
		{
			v.push_back(nums[i]);
			arrange(nums, v, i + 1);
			v.pop_back();
		}
	}
}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> v;
		arrange(nums, v, 0);
		return res;
	}



	int main()
	{
		vector<int> nums;
		int n;
		while (cin >> n)
		{
			nums.push_back(n);
			if (cin.get() == '\n')
			{
				break;
			}
		}
		subsets(nums);
	}