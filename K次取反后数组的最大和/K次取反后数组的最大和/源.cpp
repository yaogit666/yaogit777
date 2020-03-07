class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K)
	{
		vector<int> v;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] < 0)
			{
				v.push_back(A[i]);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			if (K > 0 && !v.empty())
			{
				K--;
				for (int j = 0; j < A.size(); j++)
				{
					if (A[j] == v[i])
					{
						A[j] = -A[j];
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		int sum = 0;
		int minN = A[0];
		int a = 0;
		if (K > 0)
		{
			if (K % 2 == 0)
			{
				for (int i = 0; i < A.size(); i++)
				{
					sum += A[i];
				}
			}
			else
			{
				for (int i = 1; i < A.size(); i++)
				{
					if (minN > A[i])
					{
						minN = A[i];
						a = i;
					}
				}
				A[a] = -A[a];
				for (int i = 0; i < A.size(); i++)
				{
					sum += A[i];
				}
			}
		}
		else
		{
			for (int i = 0; i < A.size(); i++)
			{
				sum += A[i];
			}
		}
		return sum;
	}
};
