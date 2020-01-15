#include<stdio.h>
#include<assert.h>
int my_strncmp(const char* dest, const char* src, int count)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (count)
	{
		if(*dest == *src)
		{
			dest++;
			src++;
		}
		count--;
	}
	return *dest - *src;
}
int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "abbb";
	int ret = my_strncmp(arr1, arr2, 3);
	printf("%d", ret);
	system("pause");
	return 0;
}