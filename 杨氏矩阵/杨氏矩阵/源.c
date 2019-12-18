#include<stdio.h>
//1 2 3
//4 5 6
//7 8 9
int find(int arr[3][3], int key, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while ((x < *px) && (y >= 0))
	{
		if (key > arr[x][y])
		{
			x++;
		}
		else if (key < arr[x][y])
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	int ret = find(arr, 7, &x, &y);
	if (ret == 1)
	{
		printf("找到了%d %d\n", x, y);
	}
	else
	{
		printf("没找到%d %d\n", x, y);
	}
	system("pause");
	return 0;
}