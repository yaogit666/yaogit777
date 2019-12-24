#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr1[5] = {0};
	int arr2[5] = {0};
	int i = 0;
	for (i = 1; i <= 5; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (i = 1; i <= 5; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (i = 1; i <= 5; i++)
	{
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr1[i] ^ arr2[i];
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 1; i <= 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	system("pause");
	return 0;
}