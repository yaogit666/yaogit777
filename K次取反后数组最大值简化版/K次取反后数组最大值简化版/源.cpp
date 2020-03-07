
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K)
	{
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size(); i++)
		{
			if (K > 0 && A[i] < 0)
			{
				K--;
				A[i] = -A[i];
			}
			else
			{
				break;
			}
		}
		int sum = 0;
		if (K > 0 && K % 2 != 0)
		{
			sort(A.begin(), A.end());
			A[0] = -A[0];
		}
		for (int i = 0; i < A.size(); i++)
		{
			sum += A[i];
		}
		return sum;
	}
};