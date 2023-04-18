#define _CRT_SECURE_NO_WARNINGS



#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int  x, int y);

void ComputerMove(char board[ROW][COL], int row, int col);