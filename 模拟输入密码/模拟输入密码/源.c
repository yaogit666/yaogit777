#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char psw[10] = "";
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		printf("����������:");
		scanf("%s", psw);
		if (strcmp(psw, "hellobit") == 0)
			break;
	}
	if (i == 3)
	{
		printf("��½ʧ��\n");
	}
	else
	{
		printf("��½�ɹ�\n");
	}
	system("pause");
	return 0;
}