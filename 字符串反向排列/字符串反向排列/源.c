#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int mystrlen(char* string)
{
	int count = 0;	
	while (*string++)
	{
		count++;
	}
	return count;
}

int reverse_string(char* string)
{
	if (*string)
	{
		char* start = string;
		char* end = start + mystrlen(string) - 1;
		char temp = *start;
		*start = *end;
		*end = '\0';
		reverse_string(start+1);
		*end = temp;
	}
	return string;
}

int main()
{
	char string[10] = "";
	scanf("%s", &string);
	printf("%s", reverse_string(string));
	system("pause");
	return 0;
}
