#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void InitBoard(int row, int col, char board[ROW][COL]);
void DisplayBoard(int row, int col, char board[ROW][COL]);
void PlayerMove(int row, int col, char board[ROW][COL]);
void ComputerMove(int row, int col, char board[ROW][COL]);
char IsWin(int row, int col, char board[ROW][COL]);