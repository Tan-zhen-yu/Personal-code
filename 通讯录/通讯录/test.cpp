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
	printf("结点值:");
	scanf("%c", &x);
	h = Level(b, x, 1);
	if (h == 0)
	{
		printf("b中不存在%c节点\n", x);
	}
	else
	{
		printf("在b中%c节点的层次为%d\n", x, h);
	}
	DestroyBTree(b);






	return 0;
}