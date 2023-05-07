
#define _CRT_SECURE_NO_WARNINGS

#include"shu.h"


int TreeHeight1(TSonNode* t)
{
	TSonNode* p;
	int i, h, maxh = 0;
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		for (i = 0; i < MaxSons; i++)
		{
			p = t->sons[i];
			if (p != NULL)
			{
				h = TreeHeight1(p);
				if (maxh < h)
				{
					maxh = h;
				}
			}
		}
		return (maxh + 1);
	}
}

int TreeHeight2(TSBNode* t)
{
	TSBNode* p;
	int h, maxh = 0;
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		p = t->vp;
		while (p != NULL)
		{
			h = TreeHeight2(p);
			if (maxh < h)
			{
				maxh = h;
			}
			p = p->hp;
		}
		return maxh + 1;
	}
}

void CreateBTree(BTNode*& b, char* str)
{
	BTNode* St[Maxsize], * p = NULL;
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
			St[top] = p;
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
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
			
		}
		j++;
		ch = str[j];
	}
}

void DestroyBTree(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);

	}
}

BTNode* FindNode(BTNode* b, ElemType x)
{
	BTNode* p;
	if (b == NULL)
	{
		return NULL;
	}
	else if (b->data == x)
	{
		return b;
	}
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;

		else
			return FindNode(b->rchild, x);
	}
}

BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}

BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}

int BTHeight(BTNode* b)
{
	int lchildh, rchildh;
	if (b == NULL)
		return 0;
	else
	{
		lchildh = BTHeight(b->lchild);
		rchildh = BTHeight(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}

void DispBTree(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL)
				printf(",");
			DispBTree(b->rchild);
			printf(")");
		}
	}
}

void PreOrder1(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		PreOrder1(b->lchild);
		PreOrder1(b->rchild);
	}
}

void PreOrder2(BTNode* b)
{
	if (b != NULL)
	{
		PreOrder2(b->lchild);
		printf("%c", b->data);
		PreOrder2(b->rchild);
	}
}

void PreOrder3(BTNode* b)
{
	if (b != NULL)
	{
		PreOrder3(b->lchild);
		PreOrder3(b->rchild);
		printf("%c", b->data);
	}
}

int Nodes(BTNode* b)
{
	if (b == NULL)
		return 0;
	else
	{
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
	}
}

void DispLeaf(BTNode* b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
			printf("%c", b->data);
		DispLeaf(b->lchild);
		DispLeaf(b->rchild);
	}
}

void DispLeaf1(BTNode* b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			printf("%c", b->data);
			DispLeaf1(b->rchild);
			DispLeaf1(b->lchild);
		}
	}
}

int Level(BTNode* b, ElemType x, int h)
{
	int l;
	if (b == NULL)
	{
		return 0;
	}
	else if (b->data == x)
		return h;
	else
	{
		l = Level(b->lchild, x, h + 1);
		if (l != 0)
			return l;
		else
			return Level(b->rchild, x, h + 1);
	}
}

void Lnodenum(BTNode* b, int h, int k, int& n)
{
	if (b == NULL)
		return;
	else
	{
		if (h == k)
		{
			n++;
		}
		else if(h<k)
		{
			Lnodenum(b->lchild, h + 1, k, n);
			Lnodenum(b->rchild, h + 1, k, n);
		}
	}
}

int n = 0;

void Lnodenum1(BTNode* b, int h, int k)
{
	if (b == NULL)
		return;
	else
	{
		if (h == k)
			n++;
		else if (h < k)
		{
			Lnodenum1(b->lchild, h + 1, k);
			Lnodenum1(b->rchild, h + 1, k);
		}
	}
}

bool Like(BTNode* b1, BTNode* b2)
{
	bool like1, like2;
	if (b1 == NULL && b2 == NULL)
		return true;
	else if (b1 == NULL || b2 == NULL)
		return false;
	else
	{
		like1 = (Like(b1->lchild, b2->lchild));
		like2 = (Like(b1->rchild, b2->rchild));
		return (like1 && like2);
	}
}

bool ancestor(BTNode* b, ElemType x)
{
	if (b == NULL)
	{
		return false;
	}
	else if (b->lchild != NULL && b->lchild->data == x || b->rchild != NULL && b->rchild->data == x)
	{
		printf("%c", b->data);
		return true;
	}
	else if (ancestor(b->lchild, x) || ancestor(b->rchild, x))
	{
		printf("%c", b->data);
		return true;
	}
	else
	{
		return false;
	}
}

BTNode* CreateBT1(char* pre, char* in, int n)
{
	BTNode* b;
	char* p;
	int k;
	if (n <= 0)
		return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = *pre;
	for (p = in; p < in + n; p++)
	{
		if (*p == *pre)
			break;
	}
	k = p - in;
	b->lchild = CreateBT1(pre + 1, in, k);
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);
	return b;
}

BTNode* CreateBTree2(char* post, char* in, int n)
{
	BTNode* b;
	char r, * p;
	int k;
	if (n <= 0)
		return NULL;
	r = *(post + n - 1);
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = r;
	for (p = in; p < in + n; p++)
	{
		if (*p == r)
			break;
	}
	k = p - in;
	b->lchild = CreateBTree2(post, in, k);
	b->rchild = CreateBTree2(post + k,p + 1, n - k - 1);
	return b;
}

BTNode* trans(SqBTree a, int i)
{

}