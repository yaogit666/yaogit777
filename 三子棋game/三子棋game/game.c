#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(int row, int col, char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}		
}

void DisplayBoard(int row, int col, char board[ROW][COL])//打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{		
		// * | * | * 
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(int row, int col, char board[ROW][COL])//玩家下棋
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("该你了>:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("输入错误\n");
			}
		}
		else
		{
			printf("输入错误\n");
		}
	}
}

void ComputerMove(int row, int col, char board[ROW][COL])//电脑下棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("电脑走>:\n");
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int IsFull(int row, int col, char board[ROW][COL])//平局
{
	int i = 0;
	int j = 0;
	for (i = 1; i < row; i++)
	{
		for (j = 1; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(int row, int col, char board[ROW][COL])
{
	int i = 0;
	//判断输赢
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//平局
	if (IsFull(row, col, board) == 1)
	{
		return 'Q';
	}
	return 'P';
}