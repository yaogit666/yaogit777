class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int M = array.size();
		int N = array[0].size();
		for (int i = M - 1, j = 0; i >= 0 && j < N;)
		{
			if (target == array[i][j])
				return true;
			else if (target < array[i][j])
				i--;
			else if (target > array[i][j])
				j++;
		}
		return false;

	}
};