#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i=0;
	int j=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}


}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (int h = 0; h < col; h++)
	{
		printf(" ---");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j == 0)
				printf("|");
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		for (int h = 0; h < col; h++)
		{
			printf(" ---");
		}
			printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int  row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走;>\n");

	printf("请输入下棋的坐标:>\n");

	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<0 || y>col)
		{
			printf("坐标不合法!请重新输入\n");
		}

		else
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入\n");
			}
		}

	}
	

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走;>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
 }
int  IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for(j=0;j<col;j++)
			if (board[i][j] == ' ')
			{
				return 0;
			}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	char win = ' ';
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
	{
		return board[0][0];
	}
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
	{
		return board[1][0];
	}
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		return board[2][0];

	}
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
	{
		return board[0][0];
	}
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
	{
		return board[0][1];
	}
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		return board[2][0];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[0][2];
	}
	int ret = IsFull(board, row, col);
		if (ret == 1)
		{
			return 'Q';
		}
		return 'C';
}