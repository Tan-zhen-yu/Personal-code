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
		/*�������*/
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret == 'Q')
		{
			printf("ƽ����\n");
			break;
		}
		else if (ret == '*')
		{
			printf("��ϲ�㣬��Ӯ��\n");
			break;
		}
			
		/*��������*/
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret == 'Q')
		{
			printf("ƽ����\n");
			break;
		}
		else if (ret == '#')
		{
			printf("���ź���������\n");
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
			printf("�˳���Ϸ\n");
			break;
		case 1:
			printf("��������Ϸ\n");
			game();
			break;
		default:
			printf("ѡ�����������ѡ��:\n");
			break;
		}
		printf("��Ҫ����	``````````````````````	`һ����\n");
	} while (input);
		


	return 0;
}


