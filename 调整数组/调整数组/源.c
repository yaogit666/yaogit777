
#include<stdio.h>
void move(int arr[], int sz)
{
	int left = 0;
	int right =sz - 1;
	int i = 0;
	while (left < right)
	{
		if ((left <= right) && (arr[left] % 2 == 1))
		{
			left++;
		}
		if ((left <= right) && (arr[right] % 2 == 0))
		{
			right--;
		}
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
}
int main()
{
	int i = 0;
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr,sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}