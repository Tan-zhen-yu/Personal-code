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
	printf("������Ϣ 1\n");
	printf("ɾ����Ϣ 2\n");
	printf("���� 3\n");
	printf("���� 4\n");
	printf("��ӡ 5\n");
	printf("��������Ҫִ�еĲ���;>\n");
	DisPlayList(L);
	while (1)
	{

		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("��������Ҫ�����λ�ú�����;>\n");
			scanf("%d%d", i, e);
			ListInsert(L, i, e);
			break;
		case 2:
			printf("��������Ҫɾ����λ��;>\n");
			scanf("%d", &i);
			ListDelete(L, i, e);
			printf("��ɾ������Ϣ�� %d", e);
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
			printf("�����������������;>\n");
			break;

		}




	}
	return 0;
}
