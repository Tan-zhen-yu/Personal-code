#define _CRT_SECURE_NO_WARNINGS
#include"zhan.h"

int main()
{
	char exp[] = "(56-20)/(4+2)";
	char postexp[Maxsize];
	trans(exp, postexp);
	
	printf("中缀表达式:%s\n", exp);
	printf("后缀表达式:%s\n", postexp);
	printf("后缀表达式的值:%g\n", compvalue(postexp));




	return 0;       
}