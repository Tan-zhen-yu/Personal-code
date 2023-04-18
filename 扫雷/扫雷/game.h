#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<math.h>

void Initborad(char board[ROWS][COLS],int rows, int cols,char p);

void Displyboard(char board[ROWS][COLS], int rows, int cols);

void Setmine(char board[ROWS][COLS], int rows, int cols);

int  Findmine(char board1[ROWS][COLS],char board2[ROWS][COLS],int rows, int cols);

int Iswin(char board[ROWS][COLS], int rows, int cols);