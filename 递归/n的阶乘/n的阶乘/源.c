#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int factorial1(int n)
{
	int i = 0;
	int j = 1;
	for (i = 1; i <= n; i++)
	{
		j = i * j;
	}
	return j;
}

int factorial2(int n)
{
	if ( n <= 1)
	{
		return 1;
	}
	return factorial2(n - 1) * n;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", factorial1(n));
	printf("%d\n", factorial2(n));
	system("pause");
	return 0;
}