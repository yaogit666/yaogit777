#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	scanf("%d", &i);
	for (j = 31; j >= 0; j--)
	{
		printf("%d", (i >> 32 - j) & 1);
	}
	system("pause");
	return 0;
}