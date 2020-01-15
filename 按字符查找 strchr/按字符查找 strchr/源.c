#include<stdio.h>
#include<assert.h>
char* my_strchr(const char* str,const char c)
{
	char* s = str;
	while (*s)
	{
		if (*s == c)
		{
			return s;
		}
		s++;
	}
	return NULL;
}
int main()
{
	char* str = "abcdef";
	char c = 'b';
	char* ret = my_strchr(str, c);
	printf("%s", ret);
	system("pause");
	return 0;
}