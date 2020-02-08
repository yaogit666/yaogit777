class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
				v2.push_back(array[i]);
			else
				v1.push_back(array[i]);
		}
		array.clear();
		for (int i = 0; i < v1.size(); i++)
		{
			array.push_back(v1[i]);
		}
		for (int i = 0; i < v2.size(); i++)
		{
			array.push_back(v2[i]);
		}
	}
};