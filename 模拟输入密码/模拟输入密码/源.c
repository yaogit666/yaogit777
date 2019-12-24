#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char psw[10] = "";
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		printf("ÇëÊäÈëÃÜÂë:");
		scanf("%s", psw);
		if (strcmp(psw, "hellobit") == 0)
			break;
	}
	if (i == 3)
	{
		printf("µÇÂ½Ê§°Ü\n");
	}
	else
	{
		printf("µÇÂ½³É¹¦\n");
	}
	system("pause");
	return 0;
}