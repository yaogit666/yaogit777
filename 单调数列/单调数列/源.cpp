class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		return smaller(A) || biger(A);
	}

	bool smaller(vector<int>& A)
	{
		for (int i = 1; i < A.size(); i++)
		{
			if (A[i - 1] > A[i])
			{
				return false;
			}
		}
		return true;
	}
	bool biger(vector<int>& A)
	{
		for (int i = 1; i < A.size(); i++)
		{
			if (A[i - 1] < A[i])
			{
				return false;
			}
		}
		return true;
	}
};