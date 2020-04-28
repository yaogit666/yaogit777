class Solution {
public:
	int convertInteger(int A, int B) {
		unsigned int res = A ^ B;
		unsigned int count = 0;
		while (res)
		{
			if (res & 1 == 1)
				count++;
			res = res >> 1;
		}
		return count;
	}
};