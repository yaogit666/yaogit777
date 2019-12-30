#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("************************\n");
	printf("**  1.paly    0.exit  **\n");
	printf("************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(ROW, COL, board);
	DisplayBoard(ROW, COL, board);
	while(1)
	{
		PlayerMove(ROW, COL,board);
		ret = IsWin(ROW, COL, board);
		if (ret != 'P')
			break; 
		DisplayBoard(ROW, COL, board);
		ComputerMove(ROW, COL, board);
		ret = IsWin(ROW, COL, board);
		if (ret != 'P')
			break;
		DisplayBoard(ROW, COL, board);
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'P')
	{
		printf("ƽ��\n");
	}
	DisplayBoard(ROW, COL, board);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}