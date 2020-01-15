#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* arr1,const char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	while (*arr1 == *arr2)
	{    
		if (*arr1 == '\0')
		{
			return 0;
		}
			arr1++;
			arr2++;
	}
		return *arr1 - *arr2;
	
}
int main()
{
	char arr1[10] = "abcdef";
	char arr2[10] = "abc";
	int ret = my_strcmp(arr1, arr2);
	printf("%d", ret);

	system("pause");
	return 0;
}