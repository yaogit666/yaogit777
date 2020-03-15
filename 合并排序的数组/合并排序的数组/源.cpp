class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		if (!B.empty())
		{
			int j = 0;
			for (int i = m; i < A.size(); i++)
			{
				A[i] = B[j];
				j++;
			}
			sort(A.begin(), A.end());
		}
	}
};