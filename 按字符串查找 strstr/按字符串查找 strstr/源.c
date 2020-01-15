#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	const char* s1 = str1; 
	const char* s2 = str2;
	const char* p = s1;
	while (*s1)
	{
		s1 = p;
		while (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return p;
		p++;
	}
}
int main()
{
	char str1[10] = "abbbcdefg";
	char str2[10] = "bbc";
	char* s = my_strstr(str1, str2);
	printf("%s", s);
	system("pause");
	return 0;
}
