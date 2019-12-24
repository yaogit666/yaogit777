#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//实现函数init（）初始化数组、
void init(int arr1[], int i, int j)
{
	for (i = 0; i <= j; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}
//实现empty（）清空数组、
void empty(int arr2[], int i,int j)
{
	for (i = 0; i <= j; i++)
	{
		arr2[i] = 0;
		printf("%d ", arr2[i]);
	}
	printf("\n");
}
//实现reverse（）函数完成数组元素的逆置。
void reverse(int arr3[], int i, int j)
{
	int left = 0;
	int right = j;
	int ret = 0;
	while(left <= right)
	{
		ret = arr3[left];
		arr3[left] = arr3[right];
		arr3[right] = ret;
		left++;
		right--;
	}
	for (i = 0; i <= j; i++)
	{
		printf("%d ", arr3[i]);
	}
}

int main()
{
	int i = 0;
	int arr[5] = {0};
	int j = sizeof (arr) / sizeof (arr[0]) - 1;
	for (i = 0; i <= j; i++)
	{
		scanf("%d ", &arr[i]);
	}
	init(arr, i, j);
	empty(arr, i, j);
	reverse(arr, i, j);
	system("pause");
	return 0;
}