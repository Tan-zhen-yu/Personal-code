#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("********* 1.play  **********\n"); 
	printf("********* 0.exit  **********\n");
	printf("****************************\n");
}
void game()
{
	int ret = 0;
	char mine[ROWS][COLS]={0};
	char show[ROWS][COLS]={0};
	
	Initborad(mine, ROWS, COLS,'0');
	Initborad(show,ROWS, COLS,'*');

	
	Setmine(mine, ROWS, COLS);

	
	while (1)
	{
		
		Displyboard(show, ROWS, COLS);

		ret =Findmine(mine, show, ROWS, COLS);
		if (ret == 0)
		{
			printf("���ź����㱻ը����\n");
			break;
		}
	 	ret = Iswin(show, ROWS, COLS);
		if (ret == 0)
		{
			Displyboard(show, ROWS, COLS);
	
			Displyboard(mine, ROWS, COLS);
			printf("��ϲ�㣬��Ӯ�ˣ�\n");
			break;
		}
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	printf("ɨ����Ϸ\n");
	menu();
	int input = 0;
	printf("��ѡ��:>\n");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			printf("ɨ��\n");
			game();
			printf("�㻹Ҫ����һ����");
				menu();
				scanf("%d", &input);
			break;
		default:
			printf("�����������������;>\n");
			break;

		}
} while (input);



	return 0;
}