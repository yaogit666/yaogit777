#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* str1,const char* str2)
{
	int ret = str1;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1++ = *str2++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "aaaaaaaaaaaaaa";
	char arr2[20] = "hello bit";
	int str = my_strcpy(arr1, arr2);
	printf("%s", str);
	system("pause");
	return 0;
}