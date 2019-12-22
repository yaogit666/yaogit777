#include<stdio.h>
int my_strlen(char* str)
{
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

void reverse_s(char* left, char* right)
{
	while (left < right)
	{
		char p = *left;
		*left = *right;
		*right = p;
		left++;
		right--;
	}
}

void reverse(char* str, int ret)
{
	//ÄæĞòÕû¸ö×Ö·û´®
	reverse_s(str, str + ret - 1);
	//ÄæĞòµ¥´Ê
	while (*str)
	{
		char* start = str;
		while ((*str != ' ') && (*str != '\0'))
		{
			str++;
		}
		reverse_s(start, str - 1);
		if (*str != '\0')
			str++;
	}
}

int main()
{
	char arr[20] = "student a am i";
	int ret = my_strlen(arr);
	reverse(arr, ret);
	printf("%s", arr);
	system("pause");
	return 0;
}