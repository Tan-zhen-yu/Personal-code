#define _CRT_SECURE_NO_WARNINGS


#include"biao.h"

int main()
{
	int n = 0;
	int  e = 0;
	int i = 1;
	printf("请输入员工人数;>\n");
	Sqlist* L = NULL;
	scanf("%d", &n);
	L = (Sqlist*)malloc(sizeof(Sqlist));
	L->length = 0;
	printf("请输入员工信息:>工号，性别，姓名\n");
	char arr1[Maxsize], arr2[Maxsize], arr3[Maxsize];
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s", arr1, arr2, arr3);
		ListInsert(L, i + 1, &arr1, &arr2, &arr3);
	}
	printf("请输入需要执行的操作;>\n");
	printf("初始化表 1\n销毁表 2\n判断顺序表是否为空 3\n输出表中内容 4\n按名字查找 5 \n按工号查找 6\n插入信息 7\n删除信息 8\n");
	int op = 0;
	int y = 0;
	do
	{
		printf("请输入需要执行的操作;>\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			/*初始化表*/
			InitList(L);
			printf("初始化成功");
			break;
		case 2:
			/*销毁表*/
			DestoryList(L);
			printf("销毁成功");
			break;
		case 3:
			/*判断表中内容*/
			if (ListEmpty(L) == 0)
			{
				printf("表为空，没有信息\n");
			}
			else if (ListEmpty(L) == 1)
			{
				printf("表中有%d个内容\n", L->length);
			}
			else if (ListEmpty(L) == -1)
			{
				printf("表已经被销毁\n");
			}
			break;

		case 4:
			/*输出表*/
			DispList(L);
			break;

		case 5:
			/*按名字查找*/
			printf("请输入需要找的名字\n");
			scanf("%s", arr1);
			e = LocateElem2(L, &arr1);
			if (e == 0)
			{
				printf("未找到表中有相关内容\n");
			}
			break;
		case 6:
			printf("请输入需要找的工号\n");
			scanf("%s", arr1);
			e = LocateElem1(L, &arr1);
			if (e == 0)
			{
				printf("未找到表中有相关内容\n");
			}
			break;
		case 7:
			printf("请输入要插入的位置:>\n");
			scanf("%d", &i);
			printf("请输入要插入的信息;>\n");
			scanf("%s%s%s", arr1, arr2, arr3);
			e = ListInsert(L, i, &arr1, &arr2, &arr3);
			if (e == 0)
			{
				printf("插入位置不合法！\n");
			}
			
			else
			{
				printf("插入成功!\n");
				DispList(L);
			}
			
			break;
		case 8:
			printf("请输入要删除的位置:>\n");
			scanf("%d", &i);
			e = ListDelete(L, i);
			if (e == 0)
			{
				printf("删除位置不合法！\n");
			}
			else
			{
				printf("删除成功!\n");
				DispList(L);
			}
			break;
		
		default:
			printf("输入错误!\n");

			break;
		}
		printf("还需要进行操作吗1/0\n");
		scanf("%d", &y);


	} while (y);


	return 0;
}