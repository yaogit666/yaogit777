#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	scanf("%d", &i);
	for (j = 31; j >= 1; j -= 2)
	{
		printf("%d", (i >> 32 - j) & 1);
	}
	printf("\n");
	for (j = 30; j >= 2; j -= 2)
	{
		printf("%d", (i >> 32 - j) & 1);
	}
	
	system("pause");
	return 0;
}