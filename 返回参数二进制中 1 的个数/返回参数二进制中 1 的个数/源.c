#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int count_one_bits1()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int j = 0;
//	int count = 0;
//	for (j = 0; j <= 32; j++)
//	{
//		if (i & 1 == 1)
//		{
//			count++;
//		}
//		i = i >> 1;		
//	}
//	return count;
//}
int count_one_bits2()
{
	int i = 0;
	scanf("%d", &i);
	int count = 0;
	while (i)
	{
		i = i & i - 1;
		count++;
	}
	return count;
}
int main()
{
	/*int ret1 = count_one_bits1();*/
	int ret2 = count_one_bits2();
	printf("%d", ret2);
	system("pause");
	return 0;
}
