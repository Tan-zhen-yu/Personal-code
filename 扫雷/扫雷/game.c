#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void Initborad(char board[ROWS][COLS], int rows, int cols,char q)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = q;
		}
	}
}

void Displyboard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	printf("-----É¨À×ÓÎÏ·------\n");
	for (j = 0; j <= COL; j++)
	{

		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
		{
			
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----É¨À×ÓÎÏ·------\n");
}

void Setmine(char board[ROWS][COLS], int rows, int cols)
{
	int count = COUNT;
	

	for (count = COUNT; count; count--)
	{
		int x = (rand() % ROW) + 1;
		int y = (rand() % COL) + 1;
		board[x][y] = '1';
	}

}


int  Findmine(char board1[ROWS][COLS], char board2[ROWS][COLS],int rows, int cols)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	char count='0';
	printf("ÇëÊäÈëÅÅÀ×Î»ÖÃ:>\n");
	scanf("%d%d", &x, &y);
	if (board1[x][y] == '1')
	{
		return 0;
	}
	else
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (board1[x + i][y + j] == '1')
				{
					count++;
				}
			}
		}
		board2[x][y] = count;
	}
}
int Iswin(char board[ROWS][COLS], int rows, int cols)

{
	int count = ROW*COL;
	int i = 0;
	int j = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if (board[i][j] != '*')
			{
				count--;
				if (count == COUNT)
				{
					return 0;
				}
				
			}
		}
	}
	return 1;
}