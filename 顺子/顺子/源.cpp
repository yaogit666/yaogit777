class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int joker = 0;
		for (int i = 0; i < 5; i++)
		{
			if (numbers[i] == 0)
				joker++;
		}

		if (joker > 4)
			return false;

		for (int i = joker + 1; i < 5; i++)
		{
			if (numbers[i] == numbers[i - 1])
				return false;
		}
		if (numbers[4] - numbers[joker] > 4)
			return false;
		return true;
	}
};