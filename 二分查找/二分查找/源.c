#include<stdio.h>
int binary_search(int arr[], int key, int left, int right)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}



int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 7;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int ret = binary_search(arr, key, left, right);
	if (ret == -1)
	{
		printf("�Ҳ���");
	}
	else
	{
		printf("�ҵ���:%d", ret);
	}
	system("pause");
}