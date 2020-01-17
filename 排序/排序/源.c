#include"±ÍÕ∑.h"

void InsertSort(int* array, int size)//≤Â»Î≈≈–Ú
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 1; i < size; i++)
	{
		n = array[i];
		j = i - 1;
		while (j >= 0 && n < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = n;
	}
}
void ShellSort(int* array, int size)//œ£∂˚≈≈–Ú
{
	int i = 0;
	int j = 0;
	int n = 0;
	int gap = 0;
	for (gap = size / 2; gap > 0; gap /= 2)
	{
		
		for (i = 1; i < size; i += gap)
		{
			n = array[i];
			j = i - gap;
			while (j >= 0 && n < array[j])
			{
				array[j + gap] = array[j];
				j-=gap;
			}
			array[j + gap] = n;
		}
	}
}
void SelectSort(int* array, int size)//—°‘Ò≈≈–Ú
{
	int i = 0;
	int j = 0;
	int min = 0;
	for (i = 0; i < 10; i++)
	{
		min = i;
		for (j = 0; j < 10; j++)
		{
			if (array[min] < array[j])
			{
				int temp = array[j];
				array[j] = array[min];
				array[min] = temp;
			}
		}

	}
}
void HeapSort(int* array, int size)//∂—≈≈–Ú
{
	for (; size > 0; --size)
	{
		int i = (size - 2) / 2;
		for (; i >= 0; --i)
		{
			HeapDown(array, i, size);
		}
		change(&array[0], &array[size - 1]);
	}
}
void BubbleSort(int* array, int size)//√∞≈›≈≈–Ú
{
	int i = 0;
	int j = 0;
	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}
void QuickSort(int* array, int left, int right)//øÏÀŸ≈≈–Ú
{
	int i = left;
	int j = right;
	int key = array[left];
	if (left >= right)
	{
		return;
	}
	while (left < right)
	{
		while (left < right && key <= array[right])
		{
			right--;
		}
		if (key > array[right])
		{
			change(&array[left], &array[right]);
			left++;
		}
		while (left < right && key >= array[left])
		{
			left++;
		}
		if (key < array[left])
		{
			change(&array[left], &array[right]);
			right--;
		}
	}
	QuickSort(array, i, left-1);
	QuickSort(array, left+1, j);
}
void MergeSort(int* array, int size);//πÈ≤¢≈≈–Ú
void CountSort(int* array, int size)//º∆ ˝≈≈–Ú
{
	int i = 0;
	int a[10];
	int b[20];
	for (i = 0; i < 20; i++)
	{
		b[i] = 0;
	}
	for (i = 0; i < 10; i++)
	{
		b[array[i]] += 1;
	}
	for (i = 1; i < 20; i++)
	{
		b[i] = b[i] + b[i - 1];
	}
	for (i = 9; i >= 0; i--)
	{
		a[b[array[i]] - 1] = array[i];
		b[array[i]] -= 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
void change(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void HeapDown(int* array,int i, int size)
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child]<array[child+1])
		{
			child += 1;
		}
		if (array[parent] < array[child])
		{
			change(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}