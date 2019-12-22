#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int my_pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	return my_pow(n, (k - 1)) * n;
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);
	printf("%d\n", my_pow(n, k));
	system("pause");
	return 0;
}