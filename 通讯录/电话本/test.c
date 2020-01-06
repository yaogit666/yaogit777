#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()
{
	printf("-------------------------------\n");
	printf("***  1. add        2. del  ****\n");
	printf("***  3. search     4. modify **\n");
	printf("***  5. show       6. empty  **\n");
	printf("***  7. sort       0. exit   **\n");
	printf("-------------------------------\n");
}

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT
};

void test()
{
	int input = 0;
	Contact c;
	InitContact(&c);
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				AddContact(&c);
				break;
			case DEL:
				DelContact(&c);
				break;
			case SEARCH:
				SearchConttact(&c);
				break;
			case MODIFY:
				ModifyContact(&c);
				break;
			case SHOW:
				ShowContact(&c);
				break;
			case EMPTY:
				EmptyContact(&c);
				break;
			case SORT:
				SortContact(&c);
				break;
			case EXIT:
				SaveContact(&c);
				ExitContact(&c);
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}