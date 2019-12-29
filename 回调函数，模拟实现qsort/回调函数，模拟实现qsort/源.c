#include<stdio.h>
int cmp(void* p1, void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

void Qsort(void* base,int count,int s)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char*)base + j * s , (char*)base+(j + 1) * s) > 0)
			{
				char tep = *((char*)base + j * s);
				*((char*)base + j * s) = *((char*)base + (j + 1) * s);
				*((char*)base + (j + 1) * s) = tep;
			}
			
		}
	}
}
int main()
{
		int arr[10] = { 0,9,8,7,6,5,4,3,2,1 };
		int i = 0;
		int sz = sizeof(arr) / sizeof(arr[0]);
		Qsort(arr, sz, sizeof(int));
		for (i = 0; i < sz; i++)
		{
			printf("%d", arr[i]);
		}
		system("pause");
		return 0;
}