#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int a = 0;
	int b = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (a = n - 1; a >= i; a--)
		{
			printf(" ");
		}
		for (b = 1; b <= 2*i-1; b++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = n-1; i >=1; i--)
	{
		for (a = i; a <= n-1; a++)
		{
			printf(" ");
		}
		for (b=1; b<=2*i-1; b++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}