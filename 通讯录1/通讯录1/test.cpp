#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void menu()
{
	printf("**********************************\n");
	printf("******    1.add    2.del     *****\n");
	printf("******    3.search 4.modify  *****\n");
	printf("******    5.sort   6.print   *****\n");
	printf("******         0.exit        *****\n");
	printf("**********************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
};

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
			printf("ÇëÑ¡Ôñ:>");
    scanf("%d", &input);
			switch (input)
			{
			case ADD:
				AddContact(&con);
				break;
			case DEL:
				DelContact(&con);
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SORT:
			    SortContact(&con);
				break;
			case PRINT:
				PrintContact(&con);
				break;
			case EXIT:
				SaveContact(&con);
				ExitContact(&con);
				break;
			default:
				printf("Ñ¡Ôñ´íÎó£¬ÇëÖØĞÂÑ¡Ôñ:>\n");
				break;

			}



	} while (input);







	return 0;
}