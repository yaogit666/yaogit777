#include<stdio.h>
#include<assert.h>
char* my_strncpy(char* dest,const char* src , int count)
{
	assert(src != NULL);
	char* ret = dest;
	while (count)
	{
		if (*src != '\0')
		{
			*dest++ = *src++;
		}
		count--;
	}
	return ret;
}
int main()
{
	char arr1[] = "hello bit";
	char arr2[] = "aaaaaaaaaaaaaaaaa";
	int ret = my_strncpy(arr2, arr1, 5);
	printf("%s", ret);
	system("pause");
	return 0;
}