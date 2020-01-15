#include<stdio.h>
#include<assert.h>
char* my_strcat(char* str1,const char* str2)
{
	assert(str2 != NULL);
	int ret = str1;
	while (*str1 != '\0') 
	{
		str1++;
	}
	while (*str1++ = *str2++)
	{
		;
	}
	return ret;
}	
int main()
{
	char arr1[] = "hello ";
	char arr2[] = "bit";
	char* str = my_strcat(arr1, arr2);
	printf("%s", str);
	system("pause");
	return 0;
}