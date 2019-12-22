#include<stdio.h>
//int chek_sys()
//{
//	int i = 1;
//	return *(char*)&i;
//}
int chek_sys()
{
	union un
	{
		char a;
		int b;
	} u;
	 u.b = 1;
		return u.a;
}

int main()
{
	if(chek_sys() == 1)
	printf("Ð¡¶Ë×Ö½ÚÐò´æ´¢\n");
	else
	printf("´ó¶Ë×Ö½ÚÐò´æ´¢\n");
	system("pause");
	return 0;
}
