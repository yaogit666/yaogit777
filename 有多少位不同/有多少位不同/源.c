#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int compare()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int ret = compare();
	printf("%d", ret);
	system("pause");
	return 0;
}