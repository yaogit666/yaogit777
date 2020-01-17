#include"БъЭЗ.h"

int main()
{
	int  i = 0;
	int array[10] = { 0,9,8,7,6,5,4,3,2,1 };
	//InsertSort(&array, 10);
	//BubbleSort(&array, 10);
	//ShellSort(&array, 10);
	//SelectSort(&array, 10);
	//HeapSort(&array, 10);
	//QuickSort(&array, 0, 9);
	//CountSort(&array, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}