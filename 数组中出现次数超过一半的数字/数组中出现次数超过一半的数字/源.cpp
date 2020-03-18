class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		sort(numbers.begin(), numbers.end());
		int len = numbers.size() / 2;
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == numbers[len])
				count++;
		}
		if (count > len)
			return numbers[len];
		else
			return 0;
	}
};