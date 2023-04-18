#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void meue()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");

}
void game()
{
	char ret = 0;
	char  board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		/*玩家下棋*/
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret == 'Q')
		{
			printf("平局了\n");
			break;
		}
		else if (ret == '*')
		{
			printf("恭喜你，你赢了\n");
			break;
		}
			
		/*电脑下棋*/
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret == 'Q')
		{
			printf("平局了\n");
			break;
		}
		else if (ret == '#')
		{
			printf("很遗憾，你输了\n");
			break;
		}

	}
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	
	do
	{
		meue();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("三子棋游戏\n");
			game();
			break;
		default:
			printf("选择错误，请重新选择:\n");
			break;
		}
		printf("还要再完	``````````````````````	`一把吗\n");
	} while (input);
		


	return 0;
}


