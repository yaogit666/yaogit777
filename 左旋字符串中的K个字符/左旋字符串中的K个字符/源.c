#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse(char *left, char *right)
{
	while (left < right)
	{
		char tep = *left;
		*left = *right;
		*right = tep;
		left++;
		right--;
	}
}

void left_move(char arr[], int k)
{
	int len = strlen(arr);
    reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
}
int main()
{
	char arr[] = "ABCD";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s", arr);
	system("pause");
	return 0;
}