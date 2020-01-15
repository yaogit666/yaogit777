#include<stdio.h>
#include<assert.h>
int my_strlen1(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str++)
	{
		count++;
	}
	return count;
}
int my_strlen2(const char* str)
{
	assert(str != NULL);
	if(*str != '\0')
	{
		return my_strlen2(str + 1) + 1;
	}
	return 0;
}
int main()
{
	char arr[20] = "hello bit";
	int ret1 = my_strlen1(arr);
	int ret2 = my_strlen2(arr);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	system("pause");
	return 0;
}