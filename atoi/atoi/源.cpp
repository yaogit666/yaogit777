class Solution {
public:
	int myAtoi(string str) {
		int res = 0;
		int i = 0;
		int falg = 1;
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			falg = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			int n = str[i] - '0';
			if (res > INT_MAX / 10)
				return falg == -1 ? INT_MIN : INT_MAX;
			if (res == INT_MAX / 10)
			{
				if (falg == 1 && n >= 7) return INT_MAX;
				if (falg == -1 && n >= 8) return INT_MIN;
			}
			res = res * 10 + n;
			i++;
		}
		return falg == -1 ? -res : res;
	}
};