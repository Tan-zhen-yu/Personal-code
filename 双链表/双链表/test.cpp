#define _CRT_SECURE_NO_WARNINGS

#include"link.h"

int main()
{
	DLinkNode* L;
	ElemType arr[Maxsize] = {1,2,3,4,5,6,7,8,9};
	CreateListR(L, arr, 9);
	int op = 0;
	int i = 0;
	int e = 0;
	printf("插入信息 1\n");
	printf("删除信息 2\n");
	printf("排序 3\n");
	printf("倒置 4\n");
	printf("打印 5\n");
	printf("请输入需要执行的操作;>\n");
	DisPlayList(L);
	while (1)
	{

		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("请输入需要插入的位置和数据;>\n");
			scanf("%d%d", i, e);
			ListInsert(L, i, e);
			break;
		case 2:
			printf("请输入需要删除的位置;>\n");
			scanf("%d", &i);
			ListDelete(L, i, e);
			printf("被删除的信息是 %d", e);
			break;
		case 3:
			sort(L);
			DisPlayList(L);
			break;
		case 4:
			reverse(L);
			DisPlayList(L);
			break;
		case 5:
			DisPlayList(L);
			break;
		default:
			printf("输入错误，请重新输入;>\n");
			break;

		}




	}
	return 0;
}
