#define _CRT_SECURE_NO_WARNINGS

#include"shu.h"
int main()
{
	BTNode* b;
	int h;
	ElemType x;
	char arr[Maxsize] = { "A(B(D(,G)),C(E,F))" };
	CreateBTree(b, arr);
	printf("b:");
	DispBTree(b);
	printf("\n");
	printf("���ֵ:");
	scanf("%c", &x);
	h = Level(b, x, 1);
	if (h == 0)
	{
		printf("b�в�����%c�ڵ�\n", x);
	}
	else
	{
		printf("��b��%c�ڵ�Ĳ��Ϊ%d\n", x, h);
	}
	DestroyBTree(b);






	return 0;
}