#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncat(char* dest,const char* src, int count)
{
	assert(src != NULL);
	assert(dest != NULL);
	char* d = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (count)
	{
		*dest++ = *src++;
		count--;
	}
	*dest = '\0';
	return d;
}
int main()
{
	char arr1[] = "hello ";
	char arr2[] = "bit";
	int ret = my_strncat(arr1, arr2, 3);
	printf("%s", ret);
	system("pause");
	return 0;
}