class Solution {
public:
	int multiply(int A, int B) {
		if (A > B)
			swap(A, B);
		int sum = B;
		while (--A)
		{
			sum += B;
		}
		return sum;
	}
};