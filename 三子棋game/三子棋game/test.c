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
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'P')
	{
		printf("平局\n");
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
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("出入错误，请重新选择\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}