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
	printf("С���ֽ���洢\n");
	else
	printf("����ֽ���洢\n");
	system("pause");
	return 0;
}
