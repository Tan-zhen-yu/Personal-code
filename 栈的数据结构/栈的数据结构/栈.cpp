#define _CRT_SECURE_NO_WARNINGS
#include"zhan.h"

int main()
{
	char exp[] = "(56-20)/(4+2)";
	char postexp[Maxsize];
	trans(exp, postexp);
	
	printf("��׺���ʽ:%s\n", exp);
	printf("��׺���ʽ:%s\n", postexp);
	printf("��׺���ʽ��ֵ:%g\n", compvalue(postexp));




	return 0;       
}