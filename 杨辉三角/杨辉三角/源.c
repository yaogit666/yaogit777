#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define N 5
int main()
{
	int arr[N][N] = { 0 };
	int i, j;
	for (i = 0; i < N; i++)
	{
		arr[i][0] = arr[i][i] = 1;
	}
	for (i = 2; i < N; i++)
	{
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}