#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fab_1(int n)
{
	if (n < 3)
		return 1;
	else
		return fab_1(n - 1) + fab_1(n - 2);
}
int fab_2(int n)
{
	int a = 1;
	int b = 1;
	int sum = 0;
	if (n < 3)
	{
		sum = a + b;
	}
	else
	{
		sum = 2;
		while (n-- > 3)
		{
			a = b;
			b = sum;
			sum = a + b;
		}
	}
	return sum;
}

int fab_3(int first, int second, int n)
{
	if (n < 3)
	{
		return 1;
	}
	if (n == 3)
	{
		return first + second;
	}
	return fab_3(second, first + second, n-1);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", fab_1(n));
	printf("%d\n", fab_2(n));
	int ret = fab_3 (1, 1, n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

