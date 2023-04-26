#define _CRT_SECURE_NO_WARNINGS

#include"shu.h"

int TreeHeight1(TSonNode* t)
{
	TSonNode* p;
	int i, h, maxh = 0;
	if (t == NULL)
		return 0;
	else
	{
		for (i = 0; i < MaxSons; i++)
		{
			p = t->sons[i];
			if (p != NULL)
			{
				h = TreeHeight1(p);
				if (maxh < h)
					maxh = h;
			}
		}
		return maxh + 1;
	}
}

int TreeHeight2(TSBNode* t)
{
	TSBNode* p;
	int h, maxh = 0;
	if (t == NULL)
		return 0;
	else
	{
		p->vp;
		while (p != NULL)
		{
			h = TreeHeight2(p);
			if (maxh < h)
				maxh = h;
			p = p->hp;
		}
		return (maxh + 1);
	}
}

void CreatBTree(BTNode*& b, char* str)
{
	BTNode* st[Maxsize], * p;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case'(':
			top++;
			st[top] = p;
			k = 1;
			break;
		case')':
			top--;
			break;
		case',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:
					st[top]->lchild = p;
					break;
				case 2:
					st[top]->lchild = p;
					break;
				}
			}

		}
		j++;
		ch = str[j];

	}
}
