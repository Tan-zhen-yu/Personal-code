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
			printf("ºÜÒÅº¶£¬Äã±»Õ¨ËÀÁË\n");
			break;
		}
	 	ret = Iswin(show, ROWS, COLS);
		if (ret == 0)
		{
			Displyboard(show, ROWS, COLS);
	
			Displyboard(mine, ROWS, COLS);
			printf("¹§Ï²Äã£¬ÄãÓ®ÁË£¡\n");
			break;
		}
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	printf("É¨À×ÓÎÏ·\n");
	menu();
	int input = 0;
	printf("ÇëÑ¡Ôñ:>\n");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case 0:
			printf("ÍË³öÓÎÏ·\n");
			break;
		case 1:
			printf("É¨À×\n");
			game();
			printf("Äã»¹ÒªÔÚÍæÒ»°ÑÂğ");
				menu();
				scanf("%d", &input);
			break;
		default:
			printf("ÊäÈë´íÎó£¬ÇëÖØĞÂÊäÈë;>\n");
			break;

		}
} while (input);



	return 0;
}