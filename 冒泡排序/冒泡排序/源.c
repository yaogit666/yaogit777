#include<stdio.h>
void cmp(int arr[],int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz ; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tep = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tep;
			}
		}
	}
}

int main()
{
	int arr[10] = { 0,9,8,7,6,5,4,3,2,1 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	cmp(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}